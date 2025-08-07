/*
 * AirScout-M v1 Firmware
 * Mobile Air Quality Monitoring System
 * Author: Airshed Intelligence
 * Version: 1.0.0
 */

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Adafruit_BME280.h>
#include <RTClib.h>
#include <ArduinoOTA.h>
#include <ArduinoJson.h>
#include "config.h"
#include "sensors.h"

// Pin Definitions
#define PMS_RX D5
#define PMS_TX D6
#define GPS_RX D7
#define GPS_TX D8
#define MQ135_PIN A0
#define SD_CS D2
#define LED_POWER D0
#define LED_WIFI D3
#define LED_ERROR D4

// Global Objects
SoftwareSerial pmsSerial(PMS_RX, PMS_TX);
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
TinyGPSPlus gps;
Adafruit_BME280 bme;
RTC_DS3231 rtc;
WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);

// Timing Variables
unsigned long lastSync = 0;
unsigned long lastSample = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("AirScout-M v1 Starting...");
  
  // Initialize Hardware
  initializePins();
  initializeSensors();
  initializeStorage();
  
  // Connect Network
  connectWiFi();
  setupMQTT();
  setupOTA();
  
  Serial.println("System Ready!");
}

void loop() {
  ArduinoOTA.handle();
  
  if (!mqtt.connected() && WiFi.status() == WL_CONNECTED) {
    reconnectMQTT();
  }
  mqtt.loop();
  
  // Sample sensors every 30 seconds
  if (millis() - lastSample > SAMPLE_INTERVAL) {
    lastSample = millis();
    collectSensorData();
    logToSD();
  }
  
  // Sync data every 15 minutes
  if (millis() - lastSync > SYNC_INTERVAL) {
    lastSync = millis();
    syncData();
  }
  
  // Process GPS data
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}

void initializePins() {
  pinMode(LED_POWER, OUTPUT);
  pinMode(LED_WIFI, OUTPUT);
  pinMode(LED_ERROR, OUTPUT);
  pinMode(MQ135_PIN, INPUT);
  digitalWrite(LED_POWER, HIGH);
}

void initializeSensors() {
  pmsSerial.begin(9600);
  gpsSerial.begin(9600);
  Wire.begin();
  
  if (!bme.begin(0x76)) {
    Serial.println("BME280 Error!");
    digitalWrite(LED_ERROR, HIGH);
  }
  
  if (!rtc.begin()) {
    Serial.println("RTC Error!");
    digitalWrite(LED_ERROR, HIGH);
  }
}

void initializeStorage() {
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card Error!");
    digitalWrite(LED_ERROR, HIGH);
  }
}