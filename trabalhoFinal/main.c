#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

#include "peca.h"

int main (){
  int qtdPecas = 24;
  struct Peca pecas[qtdPecas];
  int i, j, pos=0;

  for(int i = 0; i<6; i++){
    for(int j = 0; j<2; j++){
      struct Peca teste = {140+(i*76), 150+(j*85), 0};
      pecas[pos] = teste;
      pos++;
    }
  }
  for(int i = 0; i<6; i++){
    for(int j = 4; j<6; j++){
      struct Peca teste = {140+(i*76), 150+(j*85), 1};
      pecas[pos] = teste;
      pos++;
    }
  }

  al_init();
  al_init_font_addon();
  al_init_image_addon();
  al_install_keyboard();

  ALLEGRO_DISPLAY * display = al_create_display(726, 806);
  al_set_window_position(display, 100, 100);
  al_set_window_title(display, "surakarta");

  ALLEGRO_FONT* font = al_create_builtin_font();
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

  ALLEGRO_BITMAP * bg = al_load_bitmap("./img/fundo.png");

  ALLEGRO_BITMAP * peca1 = al_load_bitmap("./img/peca1.png");
  ALLEGRO_BITMAP * peca2 = al_load_bitmap("./img/peca2.png");
  ALLEGRO_BITMAP * seleciona = al_load_bitmap("./img/seleciona.png");
  ALLEGRO_BITMAP * opcao = al_load_bitmap("./img/opcao.png");

  ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source() );
  al_start_timer(timer);

  while(true){
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
      break;
    }

    al_draw_bitmap(bg, 0, 0, 0);
    for(int i=0; i<qtdPecas; i++){
      if(pecas[i].time==1){
        al_draw_bitmap(peca1, pecas[i].posX, pecas[i].posY, 0);
      }
      else{
        al_draw_bitmap(peca2, pecas[i].posX, pecas[i].posY, 0);
      }
    }
    al_flip_display();
  }

  al_destroy_bitmap(bg);
  al_destroy_bitmap(peca1);
  al_destroy_bitmap(peca2);
  al_destroy_bitmap(seleciona);
  al_destroy_bitmap(opcao);
  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

  return 0;
}