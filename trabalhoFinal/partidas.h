#ifndef __PATIDAS_H_
#define __PATIDAS_H_

#include "peca.h"

int getRodada();
int PvP(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6], int *rodada, ALLEGRO_FONT* font, int64_t *tempo);
int PvPc(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6], int *rodada, ALLEGRO_FONT* font, int64_t *tempo);
int partida(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6], int *rodada, ALLEGRO_FONT* font, int64_t *time, int *tipo, int *dica1, int *dica2);
void salvo(struct Posicao posicoes[6][6], int *rodada, int *tipo, ALLEGRO_FONT* font, int64_t *tempo, int *dica1, int *dica2);

#endif