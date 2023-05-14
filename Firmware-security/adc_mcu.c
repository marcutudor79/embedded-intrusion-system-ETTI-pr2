#include "adc_mcu.h"
#include "delay.h" 

unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}


unsigned int read_light() {
    
    // reads the value of the light from PORTA.0
    unsigned int light_level = read_adc(0b00000000);    
    return light_level;
}