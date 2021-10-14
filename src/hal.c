#include <xc.h>

#ifndef HAL_H
#define HAL_H

void ligaBuzzer()
void desligaBuzzer()
void habilitaEscritaDisplay()
bool isBotaoDireitaApertado()
bool isBotaoEsquerdaApertado()
uint8_t readPORTA()
bool isBotaoCimaApertado()
bool isBotaoBaixoApertado()
bool isBotaoEnterApertado()
bool isBotaoESCApertado()

void ligaBuzzer(){
    PORTAbits.RA1 = 1;
}

void desligaBuzzer(){
    PORTAbits.RA1 = 0;
}

void habilitaEscritaDisplay(){

}

bool isBotaoDireitaApertado(){
    if(PORTBbits.RB4 == 1){
        return true;
    }
    return false;
}

bool isBotaoEsquerdaApertado(){
    if(PORTBbits.RB6 == 1){
        return true;
    }
    return false;
}

bool isBotaoCimaApertado(){
    if(PORTBbits.RB7 == 1){
        return true;
    }
    return false;
}

bool isBotaoBaixoApertado(){
    if(PORTEbits.RE0 == 1){
        return true;
    }
    return false;
}

bool isBotaoESCApertado(){
    if(PORTEbits.RE1 == 1){
        return true;
    }
    return false;
}

bool isBotaoEnterApertado(){
    if(PORTEbits.RE2 == 1){
        return true;
    }
    return false;
}
uint8_t readPORTA(){
    return PORTAbits.PORTA;
}
#endif
//

