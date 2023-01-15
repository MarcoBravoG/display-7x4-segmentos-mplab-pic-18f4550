#include <xc.h>
#include <stdint.h>
#include "Bits_Configuracion.h"
#include "Libreria_Display_7SEG_AC.h"

/*=====================================================================*/
void Set_Port (int8_t value)            // Función para poner a 1 los bits del Puerto.
{
    Display_LAT|=value;                 // Configuramos con 1s los bits del Puerto.
}

/*=====================================================================*/
void Clear_Port (int8_t value)          // Función para poner a 0 los bits del Puerto.
{
    Display_LAT&=~(value);              // Configuramos con 0s los bits del Puerto.
}

/*=====================================================================*/
void Decode_Display_AC (int8_t value)   // Función para decodificar los digitos en su valor de 7 segmentos ánado común.
{
    Set_Port(A|B|C|D|E|F|G|DP);         // Ponemos a 1 todos los bits del puerto.
    switch(value)
    {
        case 0: Clear_Port(A|B|C|D|E|F);   break;  // Digito 0 
        case 1: Clear_Port(B|C);           break;  // Digito 1
        case 2: Clear_Port(A|B|E|D|G);     break;  // Digito 2
        case 3: Clear_Port(A|B|C|D|G);     break;  // Digito 3
        case 4: Clear_Port(B|C|F|G);       break;  // Digito 4
        case 5: Clear_Port(A|C|D|F|G);     break;  // Digito 5
        case 6: Clear_Port(A|C|D|E|F|G);   break;  // Digito 6
        case 7: Clear_Port(A|B|C);         break;  // Digito 7
        case 8: Clear_Port(A|B|C|D|E|F|G); break;  // Digito 8
        case 9: Clear_Port(A|B|C|F|G);     break;  // Digito 9   
    }
}

/*=====================================================================*/
void Show_Digits_Display (int16_t value) // Función para mostrar números en los display de 7 segmentos ánodo común.
{
       Thousands      = value/1000;
       value = value%1000;
       Hundred        = value/100;
       value = value%100;
       Tens           = value/10;
       Units          = value%10;
        
       Decode_Display_AC(Units);
       Multiplexor_LAT=Display_1;
       __delay_ms(10);
       Decode_Display_AC(Tens);
       Multiplexor_LAT=Display_2;
       __delay_ms(10);
       Decode_Display_AC(Hundred);
       Multiplexor_LAT=Display_3;
       __delay_ms(10);
       Decode_Display_AC(Thousands);
       Multiplexor_LAT=Display_4;
       __delay_ms(10);
}
/*=====================================================================*/