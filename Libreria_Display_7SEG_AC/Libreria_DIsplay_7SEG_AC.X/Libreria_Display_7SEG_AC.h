#ifndef XC_LIBRERIA_DISPLAY_7SEG_AC_H
#define	XC_LIBRERIA_DISPLAY_7SEG_AC_H

#include <xc.h>                             // Incluimos los registros del PIC.  
#include <stdint.h>                         // Incluimos la libreria que nos permite trabajar con variabes entersas de 8,16,32 bits.

#define Display_TRIS       TRISD            // Este será el Puerto que se conectará a los display de 7 segmentos ánodo común.
#define Display_LAT        LATD             
#define Multiplexor_TRIS   TRISB            // Este será el Puerto que se conectará a los pines que controlen la multiplexación. 
#define Multiplexor_LAT    LATB

#define Display_1 (1<<3)                    // 0b00001000
#define Display_2 (1<<2)                    // 0b00001000
#define Display_3 (1<<1)                    // 0b00001000
#define Display_4 (1<<0)                    // 0b00001000

#define A   (1<<0)                          //0b00000001
#define B   (1<<1)                          //0b00000010
#define C   (1<<2)                          //0b00000100
#define D   (1<<3)                          //0b00001000
#define E   (1<<4)                          //0b00010000
#define F   (1<<5)                          //0b00100000
#define G   (1<<6)                          //0b01000000
#define DP  (1<<7)                          //0b10000000

/*=====================================================================*/
int16_t Units        = 0;                   // Variable de 16 bits unidades.
int16_t Tens         = 0;                   // Variable de 16 bits decenas.
int16_t Hundred      = 0;                   // Variable de 16 bits centenas.
int16_t Thousands    = 0;                   // Variable de 16 bits unidades de millar.

/*=====================================================================*/
void Set_Port (int8_t value);               // Función para poner a 1 los bits del Puerto.
void Clear_Port (int8_t value);             // Función para poner a 0 los bits del Puerto.
void Decode_Display_AC (int8_t value);      // Función para decodificar los digitos en su valor de 7 segmentos ánado común.
void Show_Digits_Display (int16_t value);   // Función para mostrar números en los display de 7 segmentos ánodo común.

#endif	/* XC_LIBRERIA_DISPLAY_7SEG_AC_H */
/*=====================================================================*/