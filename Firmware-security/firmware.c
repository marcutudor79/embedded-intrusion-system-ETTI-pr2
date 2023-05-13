// I/O Registers definitions
#include <mega164a.h>
#include <delay.h>
#include <stdio.h>
#include "initialise_mcu.h"
#include "adc_mcu.h"
#include "alarm_mcu.h"

void main(void) {
    unsigned int light = 0;
    if (!initialise_mcu())
        while (1) {    
              light = 0;          
              light = read_light();
              
              /* Wait for empty transmit buffer */
              printf("light level: %d \n", light);
    
              
              //ring_alarm();
                
              heartbeat_mcu();
              
        }
}
