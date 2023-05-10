#include <mega164a.h>
#include <delay.h>

void ring_alarm(){
    
    int i;
    for (i = 0; i < 4; i++) {
        PORTD.4 = 0;
        delay_ms(200);
        PORTD.4 = 1;
        delay_ms(200);
    }
    
    PORTD.4 = 0;
}