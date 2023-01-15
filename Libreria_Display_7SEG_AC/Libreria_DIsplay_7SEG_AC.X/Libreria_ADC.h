
#ifndef XC_LIBRERIA_ADC_H
#define	XC_LIBRERIA_ADC_H

#include <xc.h> 
void ADC_Init(uint8_t entradas_analogicas, uint8_t Vref, uint8_t Clock, uint8_t ADQT, uint8_t justificacion, uint8_t estado);
uint16_t Leer_Canal_ADC(uint8_t Canal);
#endif	/* XC_LIBRERIA_ADC_H */

