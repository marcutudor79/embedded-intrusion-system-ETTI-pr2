
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
```
#include "initialise_mcu.h"
void main(void) {
    
    /* initialize stuff */
    
    // turn on the laser
    PORTD.4 = 1;
    
    
    while (1) {
        
        // if it is the first loop, delay the read of adc by 100ms
        if (firstRun == 0) {
            firstRun = 1;
            delay_ms(100);        
        }    
        
        // reads the light from the sensor with laser shining on it                       
        light = read_light();
        
        // debug printf    
        printf("sensor light: %u, random_check: %d, env_light: %u \n", light, randomCheck_counter, env_light);
    
        // checks if the laser is shining on the sensor
        if (light <= env_light) {  
            // Turn on red led
            PORTD.6 = 1;          
            // Turn off blue led
            PORTB.0 = 1;
            while(1){    
            ring_alarm();
            }
        }
                
        // checks randomly within maximum 30s if the light in the environment has changed             
        if (randomCheck_counter == 0) {            
            randomCheck_counter = rand() % 70;            
            PORTD.4 = 0;            
            if (PORTD.4 != 0) 
                PORTD.4 = 0;                            
            delay_ms(100);
            env_light = read_light();
            PORTD.4 = 1;
            delay_ms(100);
        }
        
        randomCheck_counter -= 1;           
              
    }
}
```

## How to use the project
- To compile the project you need to download CVAVR from [here](https://hpinfotech.ro/cvavr-download.html).
- To flash the microcontroller you will need AVRBuster from [here](http://ham.elcom.pub.ro/proiect2/files/pcloader.zip)
- ! Please be sure to have a bootloader flashed into the AVR microcontroller !

## License 
Apache-2.0 license
