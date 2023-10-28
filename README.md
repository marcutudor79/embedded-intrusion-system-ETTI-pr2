
# ATMELMega laser detection system
![image](https://etti.upb.ro/wp-content/uploads/2023/09/ETTI-LOGO-A-1.webp)

## Description
This is the project 2 course of Electronics and Telecommunication Faculty. For this project I have worked
with @lena0097. The motivation was to solve the issue of not knowing if a door is left open or not, if
you are not physically there of course :).

## What you will find here
* Docs - contains most of the documentation for the project
* Firmware-security - contains the code project 
* Firmare-test - contains a blinky like project
* PCB - contains a KiCAD electrical scheme of the project

## What it does
1. The photoresistor has laser diode shining light on it
2. The mcu measures the voltage drop on the sensing resistor
3. If the light shined upon the photoresistor <= than ambiental light -> triggers an alarm
4. If the light shined upon the photoresistor > ambiental light -> goes back to the 1st step

## How to use the project
- To compile the project you need to download CVAVR from [here](https://hpinfotech.ro/cvavr-download.html).
- To flash the microcontroller you will need AVRBuster from [here](http://ham.elcom.pub.ro/proiect2/files/pcloader.zip)
- ! Please be sure to have a bootloader flashed into the AVR microcontroller !

## License 
Apache-2.0 license
