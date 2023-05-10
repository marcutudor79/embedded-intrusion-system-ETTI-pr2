// I/O Registers definitions
#include <mega164a.h>
#include <delay.h>
#include <stdio.h>
#include "initialise_mcu.h"
#include "adc_mcu.h"
#include "alarm_mcu.h"

void main(void) {
    unsigned char light_level = 0;
    if (!initialise_mcu())
        while (1) {    
                        
              light_level = read_light();
              
              /* Wait for empty transmit buffer */
              printf("light level: %d \n", light_level);
    
              
              //ring_alarm();
                
              heartbeat_mcu();
              
        }
}
