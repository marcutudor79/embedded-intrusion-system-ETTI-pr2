#include <mega164a.h>
#include <stdio.h>
#include "delay.h"
#include "adc_mcu.h"


void ring_alarm();
    /*  Activates the piezo element on the board 
        Turns on the RED Led in order to signal a state of alarm. 
        The Blue led is turned off.
    */


char laser_spoof_check(unsigned int env_light, char* counter) ;        
    /* Checks if a another laser shines on the sensor in order
        to spoof the laser of the system.        
    */
