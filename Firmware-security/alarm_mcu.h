 #include <mega164a.h>
#include <delay.h>

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
            
        printf("counter value is: %u \n", counter);
                
        PORTD.4 = 0;
        delay_ms(50);
                
        light_check = read_light(); 
        
        printf("env light is: %d, light_check is %d", env_light, light_check);
        printf("light level diff is: %d \n",  light_check - env_light);
                
        if ((int)(light_check - env_light) > 50) {
            return 1;                
        }                
                 
        PORTD.4 = 1;
        delay_ms(100);
        *counter = 0;
    }
    
    *counter += 1;
    return 0;
}