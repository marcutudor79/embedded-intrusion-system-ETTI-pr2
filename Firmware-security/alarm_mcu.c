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

