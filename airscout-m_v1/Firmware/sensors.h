#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <SoftwareSerial.h>

struct PMS5003_data {
  uint16_t pm1_0_std;
  uint16_t pm2_5_std;
  uint16_t pm10_std;
  uint16_t pm1_0_atm;
  uint16_t pm2_5_atm;
  uint16_t pm10_atm;
};

struct SensorData {
  float temperature;
  float humidity;
  float pressure;
  uint16_t pm1_0;
  uint16_t pm2_5;
  uint16_t pm10;
  float co_ppm;
  float no2_ppm;
  float latitude;
  float longitude;
  float altitude;
  uint32_t timestamp;
};

bool readPMS5003(SoftwareSerial &serial, PMS5003_data &data);
float calculateCO_PPM(int analogValue);
float calculateNO2_PPM(int analogValue);

#endif