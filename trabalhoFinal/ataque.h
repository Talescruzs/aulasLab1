#ifndef __ATAQUE_H_
#define __ATAQUE_H_
#include "peca.h"

void direitaSuperior(struct Posicao posicoes[6][6], int linha, int coluna);
void esquerdaSuperior(struct Posicao posicoes[6][6], int linha, int coluna);
void direitaInferior(struct Posicao posicoes[6][6], int linha, int coluna);
void esquerdaInferior(struct Posicao posicoes[6][6], int linha, int coluna);

#endif