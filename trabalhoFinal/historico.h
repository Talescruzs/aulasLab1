#ifndef __HISTORICO_H_
#define __HISTORICO_H_

#include "partidas.h"

struct Historico{
    int rodada, partida, tipo, vencedor, tempo;
};
void getHistorico(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, ALLEGRO_FONT* font, int *continua);
void addHistorico(int *rodada, int vencedor, int tipo, int64_t tempo);
void telaAjuda(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, ALLEGRO_FONT* font, int *continua, int parte);

#endif