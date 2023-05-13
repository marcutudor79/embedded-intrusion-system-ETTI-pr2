// I/O Registers definitions
#include <mega164a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "initialise_mcu.h"
#include "adc_mcu.h"
#include "alarm_mcu.h"

void main(void) {
    
    unsigned int light = 0;
    unsigned int env_light = 0;
    char counter = 0;
    int random_check = rand() % 300;
        
    initialise_mcu();    
    env_light = read_light();
    
    delay_ms(500);
    PORTD.4 = 1;
    
    while (1) {    
                               
        light = read_light();
            
        /* Wait for empty transmit buffer */
        printf("sensor light: %u \n, random_check: %d", light, random_check);
    
        if (light <= env_light) {
            ring_alarm();
        }
              
        if(laser_spoof_check(env_light, &counter)) {
            ring_alarm();
        }
                
                    
        if (random_check == 0) {
            
            printf("RANDOM CHECK!");
            random_check = rand() % 300;            
            PORTD.4 = 0;
            delay_ms(15);            
            env_light = read_light();
            
            PORTD.4 = 1;
        }
        
        random_check -= 1;  
        heartbeat_mcu();             
              
    }
}
