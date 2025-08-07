#include "sensors.h"

bool readPMS5003(SoftwareSerial &serial, PMS5003_data &data) {
  uint8_t buffer[32];
  uint16_t sum = 0;
  
  if (serial.available() >= 32) {
    if (serial.read() == 0x42 && serial.read() == 0x4D) {
      serial.readBytes(buffer, 30);
      
      for (uint8_t i = 0; i < 28; i++) {
        sum += buffer[i];
      }
      
      uint16_t checksum = (buffer[28] << 8) | buffer[29];
      
      if (sum == checksum) {
        data.pm1_0_std = (buffer[2] << 8) | buffer[3];
        data.pm2_5_std = (buffer[4] << 8) | buffer[5];
        data.pm10_std = (buffer[6] << 8) | buffer[7];
        data.pm1_0_atm = (buffer[8] << 8) | buffer[9];
        data.pm2_5_atm = (buffer[10] << 8) | buffer[11];
        data.pm10_atm = (buffer[12] << 8) | buffer[13];
        return true;
      }
    }
  }
  return false;
}

float calculateCO_PPM(int analogValue) {
  float voltage = (analogValue / 1024.0) * 3.3;
  float Rs = ((3.3 * 10.0) / voltage) - 10.0;
  float ratio = Rs / 10.0;
  return 116.6 * pow(ratio, -2.769);
}

float calculateNO2_PPM(int analogValue) {
  float voltage = (analogValue / 1024.0) * 3.3;
  float Rs = ((3.3 * 10.0) / voltage) - 10.0;
  float ratio = Rs / 10.0;
  return 0.4 * pow(ratio, 1.4);
}