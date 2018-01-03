# ESP32

## Setup
1. Install ESP32 [Arduino Core](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/mac.md)
*  Note: this seems to be incompatible with existing installations of the ESP8266 libraries
3. Open Arduino IDE, select Board > ESP Dev Module
2. Install SSD1306 (see library folder)
4. Upload ESP-DrawLogo ([source](https://hackaday.io/project/26991-esp32-board-wifi-lora-32))

## ThingSpeak (WIP)

1. Sign up for a Matlab account
2. Sign in to Thinkspeak
3. Create a new channel
3. Locate and copy its Write API key
5. Adapt [this 8266 code](https://github.com/nothans/ESP8266/blob/master/examples/RSSI_to_ThingSpeak.ino)
