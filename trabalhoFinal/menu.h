#ifndef __MENU_H_
#define __MENU_H_
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

void criaBt(ALLEGRO_EVENT *event, int posX, int posY, int tamX, int tamY, ALLEGRO_BITMAP * img1, ALLEGRO_BITMAP * img2, int *apertou, int *inbt);
int menu(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue);

#endif