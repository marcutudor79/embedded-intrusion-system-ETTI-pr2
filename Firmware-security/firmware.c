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
    
    delay_ms(50);
    PORTD.4 = 1;
    
    while (1) {    
                               
        light = read_light();
        delay_ms(50);
            
        /* Wait for empty transmit buffer */
        printf("sensor light: %u, random_check: %d, env_light: %u \n", light, random_check, env_light);
    
        if (light <= env_light + 10) {
            ring_alarm();
        }
              
        if(laser_spoof_check(env_light, &counter)) {
            ring_alarm();
        }
                
                    
        if (random_check == 0) {
            
            printf("RANDOM CHECK! \n");
            random_check = rand() % 300;            
            PORTD.4 = 0;
            delay_ms(50);            
            env_light = read_light();
            delay_ms(50);
            PORTD.4 = 1;
            delay_ms(100);
        }
        
        random_check -= 1;  
        heartbeat_mcu();             
              
    }
}
