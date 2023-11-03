#ifndef __PATIDAS_H_
#define __PATIDAS_H_

#include "peca.h"

int PvP(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6]);
int PvPc(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6]);
void salvo(struct Posicao posicoes[6][6], int *rodada, int *tipo);

#endif