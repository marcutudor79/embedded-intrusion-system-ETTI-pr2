// DEBUG VERSION

#include "initialise_mcu.h"


void main(void) {
    
    // initialize variable for light on sensor        
    unsigned int light = 0;
    
    // initialize variable for the light in the environment value
    unsigned int env_light = 0;
    
    // initialize counters for random + spoof checks + first run of the loop
    char firstRun = 0;
    char alarmRing = 0;
    char randomCheck_counter = rand() % 70;
    
    
    // initialize ports on mcu and the adc    
    initialise_mcu();
    
    // reads the light from the sensor without laser shining on it   
    env_light = read_light();
    delay_ms(100);
    
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
            //ring_alarm();
            if (alarmRing == 0) {
                PORTD.6 = 1;
                PORTB.0 = 1;
                alarmRing = 1;
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
