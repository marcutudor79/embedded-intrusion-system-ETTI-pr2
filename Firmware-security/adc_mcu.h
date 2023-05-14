#include <mega164a.h>
// Voltage Reference: 2.56V internal reference
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))

unsigned int read_adc(unsigned char adc_input);
    /*  Function that returns the analog voltage of a PORTA pin
        
    */


unsigned int read_light();
    /*  Function used to read the voltage on the light 
        sensor particullary conected to PORTA.0
        
        Returns the value of a the voltage    
    */
