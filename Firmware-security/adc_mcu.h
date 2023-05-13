#define ADMUX_NOCHANNEL 0b11100000  
// Voltage Reference: AVCC pin
#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))


unsigned int read_voltage(unsigned char channel) {

    //channel &= 0b00000111; // max 111, orice al?i bi?i tb. pu?i pe 0
    //ADMUX = ADMUX_NOCHANNEL | channel; // selectare canal 0 .. 7 (000 .. 111)
    ADMUX=channel | ADC_VREF_TYPE;
//    ADCSRA |= 0b01000000; // start conversie setînd bit ADSC=1
//    while (ADCSRA & 0b01000000); // a?teapta rezult; ADSC=1 în timpul conv.    
//    ADCSRA |= 0b00010000;

// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
//    return ADCH;
return ADCW; 
}




unsigned int read_light() {
    unsigned int light_level = read_voltage(0b00000001);    
    return light_level;
}