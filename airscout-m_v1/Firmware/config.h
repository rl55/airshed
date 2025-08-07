#ifndef CONFIG_H
#define CONFIG_H

// Network Configuration
const char* WIFI_SSID = "AirScout_Network";
const char* WIFI_PASSWORD = "SecurePassword123";
const char* MQTT_SERVER = "mqtt.airshed.in";
const int MQTT_PORT = 1883;
const char* DEVICE_ID = "AIRSCOUT_001";
const char* API_ENDPOINT = "http://api.airshed.in/v1/data";

// Timing Configuration (in milliseconds)
const unsigned long SAMPLE_INTERVAL = 30000;  // 30 seconds
const unsigned long SYNC_INTERVAL = 900000;   // 15 minutes

// Sensor Calibration
const float MQ135_R0 = 10.0;  // Baseline resistance in clean air
const float BME_ALTITUDE = 200.0;  // Local altitude in meters

#endif