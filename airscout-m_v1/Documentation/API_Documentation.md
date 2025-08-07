# AirScout API Documentation

## Data Format

### MQTT Message Structure
```json
{
  "device_id": "AIRSCOUT_001",
  "timestamp": 1704067200,
  "location": {
    "lat": 28.6139,
    "lon": 77.2090,
    "alt": 216.5
  },
  "environment": {
    "temperature": 25.3,
    "humidity": 65.2,
    "pressure": 1013.25
  },
  "air_quality": {
    "pm1_0": 12,
    "pm2_5": 35,
    "pm10": 48,
    "co": 2.3,
    "no2": 0.8
  }
}
```

## Endpoints

### HTTP POST
- URL: `http://api.airshed.in/v1/data`
- Method: POST
- Headers: Content-Type: application/json
- Body: JSON as above

### MQTT
- Broker: mqtt.airshed.in:1883
- Publish Topic: airscout/data
- Subscribe Topic: airscout/command
- QoS: 1

## Response Codes
- 200: Success
- 400: Invalid data format
- 401: Authentication failed
- 500: Server error

## Rate Limits
- 240 requests per hour per device
- Burst: 10 requests per minute

## Authentication
Device ID must be registered in the system.
Contact support@airshed.in for registration.