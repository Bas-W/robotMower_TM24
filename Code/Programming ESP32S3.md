# How to Program the ESP32S3 Wroom 1 N8R8

## Connections to ESP32 Dev module
### UART
|ESP32S3|ESP32 Dev Module|
|-------|----------------|
|3V3|3V3|
|GND|GND|
|RX|RX|
|TX|TX|

Connect the ESP32 Dev Module's EN pin to GND.

### USB
Or you can use the USB-B jack to connect straight to your laptop.
Don't forget to enable ***USB CDC On Boot*** in the tools menu.

## Programming ESP32S3
Board: ESP32S3 Dev Module

1. Press and hold the Boot Button.
2. Press and Release the EN/Reset Button.
3. Release the Boot Button.

Upload the program to the ESP32 Dev Module and after the upload is compleet, press the reset button once more so that the ESP32S3 will be reset.