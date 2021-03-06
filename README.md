# ESP32

## Shaving the Yak
I had some trouble with conflicting libraries(?), so I decided to do a fresh install of the Arduino IDE (OSX)
1. Delete Arduino IDE from Applications
2. Backup/delete Arduino folder from Documents
3. Tried to install new IDE in user Applications, didn't work
4. Updated Java, didn't work
5. Moved IDE to top-level Applications, worked
6. Looks like old board defs are still there, more research required

## Setup
1. Install ESP32 [Arduino Core](https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/mac.md)
2. Open Arduino IDE, select Board > Heltec Wifi Kit 32 (or match your hardware)
3. Install ACROBOTIC SSD1306 Library via IDE library manager
*  Note that included ACROBOTIC 1306 examples do not work out of the box ([source](https://hackaday.io/project/26991-esp32-board-wifi-lora-32))

## ThingSpeak

1. Sign up for a Matlab account
2. Sign in to Thinkspeak
3. Create a new channel
4. Locate and copy its Write API key and Channel ID
5. Edit Arduino > ESP32_Thingspeak_OLED to reflect your network's SSID/PW and your Thingspeak channel info
