# Arduino API Health Check
### Created By [NickDoxa](https://github.com/NickDoxa)

Required components:
- Arduino Nano ESP32
- Potentiometer
- Breadboard / Solder
- Liquid Crystal Display (preferably I2C)

##Define variables
You will need to create a `config.h` file with your defined variables for your ESP32 wifi connection:

```cpp
#ifndef CONFIG_H
#define CONFIG_H

#define WIFI_SSID "your_network"
#define WIFI_PASSWORD "your_password"
#define API_ENDPOINT "your_api_health_endpoint"

#endif
```

## Arduino INO Script
Next you will need to implement the provided `.ino` script in this repository. I named mine `ConduitPing.ino` because my app is called 'Conduit'.
Make sure you have the right USB-C cable to push the script using the [Arduino IDE](https://www.arduino.cc/en/software)

**Note**: Depending on how you have your pins wired from your ESP32 to your LCD you may need to change the defined pin numbers in the `.ino` script
