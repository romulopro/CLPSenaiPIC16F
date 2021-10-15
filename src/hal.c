

#ifndef HAL_H
#define HAL_H
#include <xc.h>
#include "hal.h"
#include <stdint.h>
#include <stdbool.h>
#ifdef TEST
#include "stub_pic16f877a.h"
#endif
void ligaBuzzer(){
    PORTAbits.RA1 = 1;
}

void desligaBuzzer(){
    PORTAbits.RA1 = 0;
}

void habilitaEscritaDisplay(){
    return;
}

bool isBotaoDireitaApertado(){
    return PORTBbits.RB4 == 1;
}

bool isBotaoEsquerdaApertado(){
    return PORTBbits.RB6 == 1;
}

bool isBotaoCimaApertado(){
    return PORTBbits.RB7 == 1;
}

bool isBotaoBaixoApertado(){
    return PORTEbits.RE0 == 1;
}

bool isBotaoESCApertado(){
    return PORTEbits.RE1 == 1;
}

bool isBotaoEnterApertado(){
    return PORTEbits.RE2 == 1;
}
PORTAbits_t readPORTA(){
    return PORTAbits;
}

PORTCbits_t readPORTC(){
    return PORTCbits;
}
extern void inline set_RB5(){
    PORTBbits.RB5 = 1;
}

extern void inline clear_RB5(){
    PORTBbits.RB5 = 0;
}
extern void inline set_RA3(){
    PORTAbits.RA3 = 1;
}

extern void inline clear_RA3(){
    PORTAbits.RA3 = 0;
}
extern void inline set_RA2(){
    PORTAbits.RA2 = 1;
}

extern void inline clear_RA2(){
    PORTAbits.RA2 = 0;
}

#endif
//

