#include "alarm_mcu.h"

void ring_alarm(){
    short int i;
        
    for (i = 0; i < 4; i++) {
        PORTD.3 = 0;
        delay_ms(200);
        PORTD.3 = 1;
        delay_ms(200);
    }
    
    PORTD.3 = 0;
}

char laser_spoof_check(unsigned int env_light, char* counter) {        

    if (*counter == 60) {
      
        unsigned int light_check = 0; 
                        
        PORTD.4 = 0;
        delay_ms(100);
                
        light_check = read_light(); 
        
        if ((int)(light_check - env_light) > 50) {
            PORTD.4 = 1;
            delay_ms(100);
            *counter = 0;
            return 1;                
        }                
                 
        
    }
    
    *counter += 1;
    return 0;
}
