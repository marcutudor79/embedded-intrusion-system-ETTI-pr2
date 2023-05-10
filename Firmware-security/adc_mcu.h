#define ADMUX_NOCHANNEL 0b01100000  

unsigned char read_voltage(unsigned char channel) {

    channel &= 0b00000111; // max 111, orice al?i bi?i tb. pu?i pe 0
    ADMUX = ADMUX_NOCHANNEL | channel; // selectare canal 0 .. 7 (000 .. 111)
    ADCSRA |= 0b01000000; // start conversie setînd bit ADSC=1
    while (ADCSRA & 0b01000000); // a?teapta rezult; ADSC=1 în timpul conv.    
    ADCSRA |= 0b00010000;
    return ADCH; 
}

unsigned char read_light() {
    unsigned char light_level = read_voltage(0b00000000);    
    return light_level;
}