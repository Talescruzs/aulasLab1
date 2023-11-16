#ifndef __ATAQUE_H_
#define __ATAQUE_H_
#include "peca.h"

void direitaSuperior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time);
void esquerdaSuperior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time);
void direitaInferior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time);
void esquerdaInferior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time);

#endif