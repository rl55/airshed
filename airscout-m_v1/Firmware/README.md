# AirScout-M v1 Firmware

## Installation Instructions

1. Install Arduino IDE (1.8.13 or later)
2. Add ESP8266 board support:
   - File → Preferences → Additional Board Manager URLs
   - Add: http://arduino.esp8266.com/stable/package_esp8266com_index.json
3. Install required libraries:
   - ESP8266WiFi
   - PubSubClient
   - Adafruit_BME280
   - TinyGPSPlus
   - RTClib
   - ArduinoJson
   - ArduinoOTA

## Configuration

Edit `config.h` to set:
- WiFi credentials
- MQTT server details
- Device ID
- Sampling intervals

## Flashing

1. Connect NodeMCU via USB
2. Select Board: NodeMCU 1.0 (ESP-12E Module)
3. Select Port: COM* (Windows) or /dev/ttyUSB* (Linux)
4. Click Upload

## OTA Updates

After initial flash, device supports Over-The-Air updates:
- Password: AirScoutOTA
- Hostname: AIRSCOUT_001

## Troubleshooting

LED Indicators:
- Power (D0): Solid = System powered
- WiFi (D3): Solid = Connected, Blinking = Connecting
- Error (D4): Solid = Sensor error

## API Endpoints

- MQTT Topic: airscout/data
- HTTP POST: http://api.airshed.in/v1/data
- Data Format: JSON

## License

MIT License - Airshed Intelligence 2025