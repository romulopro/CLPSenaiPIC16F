#ifndef HAL_H
#define HAL_H

#include <stdint.h>
#include <stdbool.h>

void ligaBuzzer(void);
void desligaBuzzer(void);
void habilitaEscritaDisplay(void);
bool isBotaoDireitaApertado(void);
bool isBotaoEsquerdaApertado(void);
uint8_t readPORTA(void);
bool isBotaoCimaApertado(void);
bool isBotaoBaixoApertado(void);
bool isBotaoEnterApertado(void);
bool isBotaoESCApertado(void);
void set_RB5(void);

void clear_RB5(void);
void set_RA3(void);

void clear_RA3(void);
void set_RA2(void);

void clear_RA2(void);
#endif
