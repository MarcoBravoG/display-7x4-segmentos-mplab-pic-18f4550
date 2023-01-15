#include <stdint.h>
#include "Libreria_ADC.h"
#define _XTAL_FREQ 8000000

void ADC_Init(uint8_t entradas_analogicas, uint8_t Vref, uint8_t Clock, uint8_t ADQT, uint8_t justificacion, uint8_t estado) 
{
    ADCON1bits.PCFG=entradas_analogicas;    // ADCON1bits.PCFG 
                                            //      PCFG AN12  AN11  AN10  AN9  AN8  AN7  AN6  AN5  AN4  AN3  AN2  AN1  AN0
                                            // 0    0000 A     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 1    0001 A     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 2    0010 A     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 3    0011 D     A     A     A    A    A    A    A    A    A    A    A    A 
                                            // 4    0100 D     D     A     A    A    A    A    A    A    A    A    A    A 
                                            // 5    0101 D     D     D     A    A    A    A    A    A    A    A    A    A 
                                            // 6    0110 D     D     D     D    A    A    A    A    A    A    A    A    A 
                                            // 7    0111 D     D     D     D    D    A    A    A    A    A    A    A    A 
                                            // 8    1000 D     D     D     D    D    D    A    A    A    A    A    A    A 
                                            // 9    1001 D     D     D     D    D    D    D    A    A    A    A    A    A     
                                            //10    1010 D     D     D     D    D    D    D    D    A    A    A    A    A 
                                            //11    1011 D     D     D     D    D    D    D    D    D    A    A    A    A 
                                            //12    1100 D     D     D     D    D    D    D    D    D    D    A    A    A 
                                            //13    1101 D     D     D     D    D    D    D    D    D    D    D    A    A 
                                            //14    1110 D     D     D     D    D    D    D    D    D    D    D    D    A 
                                            //15    1111 D     D     D     D    D    D    D    D    D    D    D    D    D 
    
    ADCON1bits.VCFG=Vref;                   // ADCON1bits.VCFG
                                            // Vref     VCFG1   VCFG0   
                                            // 3        1       1       Vref- (AN2)     Vref+ (AN3)
                                            // 0        0       0       Vss             Vdd 
    
    ADCON2bits.ADCS=Clock;                  // ADCON2bits.ADCS >> TAD debe ser mayor a 0.7us
                                            // Clock  ADCS     TAD
                                            // 0      000      2*Tosc
                                            // 1      001      8*Tosc
                                            // 2      010      32*Tosc
                                            // 3      011      Frc
                                            // 4      100      4*Tosc
                                            // 5      101      16*Tosc
                                            // 6      110      64*Tosc
                                            // 7      111      Frc
    
    ADCON2bits.ACQT=ADQT;                   // ADCON2bits.ACQT >> El tiempo de adquisición debe ser mayor a 2.45us
                                            // ADQT   ACQT      Tiempo de adquisición
                                            // 0      000       0*TAD
                                            // 1      001       2*TAD
                                            // 2      010       4*TAD
                                            // 3      011       6*TAD
                                            // 4      100       8*TAD
                                            // 5      101       12*TAD
                                            // 6      110       16*TAD
                                            // 7      111       20*TAD
    
    ADCON2bits.ADFM=justificacion;          // ADFM
                                            // 0        Izquierda
                                            // 1        Derecha
    
    ADCON0bits.ADON=estado;                 // ADON
                                            // 0        Deshabilitado
                                            // 1        Habilitado
   }

uint16_t Leer_Canal_ADC(uint8_t Canal)
{
    uint16_t ADC;                       // Variable que retornará el valor de los registros ADRESH y ADRESL.
    ADCON0bits.CHS=Canal;               // ADCON0bitsCHS
                                        // Canal 
                                        // 0        0000 = Channel 0 (AN0)
                                        // 1        0001 = Channel 1 (AN1)
                                        // 2        0010 = Channel 2 (AN2)
                                        // 3        0011 = Channel 3 (AN3)
                                        // 4        0100 = Channel 4 (AN4)
                                        // 5        0101 = Channel 5 (AN5)(1,2)
                                        // 6        0110 = Channel 6 (AN6)(1,2)
                                        // 7        0111 = Channel 7 (AN7)(1,2)
                                        // 8        1000 = Channel 8 (AN8)
                                        // 9        1001 = Channel 9 (AN9)
                                        //10        1010 = Channel 10 (AN10)
                                        //11        1011 = Channel 11 (AN11)
                                        //12        1100 = Channel 12 (AN12)
    
    
    ADCON0bits.ADON=1;
    ADCON0bits.GO_DONE=1;               // Inicializamos la conversión 
    while(ADCON0bits.GO_DONE==1);       // Esperamos ha que termine la conversión.
    ADCON0bits.ADON=0;
    ADC=ADRESH;                         // Cargamos ADC con los 8 bits del registro ADRESH
    ADC=ADC<<8;                         // Desplazamos 8 bits a la izquierda del registro ADC.
    ADC|=ADRESL;                        // Realizamos una operación lógica OR entre ADC y ADRESL el resultado se almacena en ADC
    __delay_ms(4);
    return ADC;
}


