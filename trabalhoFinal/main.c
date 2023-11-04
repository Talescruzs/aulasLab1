#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "peca.h"
#include "menu.h"
#include "partidas.h"

int main (){
  int linhas = 6;
  int colunas = 6;
  int rodada=1;
  int tipo=0;

  struct Posicao posicoes[linhas][colunas];

  int i, j, pos=0;
  
  

  al_init();
  al_init_font_addon();
  al_init_image_addon();
  al_install_mouse();

  ALLEGRO_DISPLAY * display = al_create_display(850, 806);
  al_set_window_position(display, 100, 100);
  al_set_window_title(display, "surakarta");

  ALLEGRO_FONT* font = al_create_builtin_font();
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

  ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_mouse_event_source() );
  al_start_timer(timer);

  int continua=1, opcaoMenu;
  while(continua==1){
    opcaoMenu=0;
    if(tipo==0){
      for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
        struct Posicao posicao = {140+(i*76), 150+(j*85), 0, 0, 0};
          if(j<2)
            posicao.estado=2;
          else if(j>3)
            posicao.estado=1;

          posicoes[i][j] = posicao;
        }
      }
    }
    if(tipo==0){
      opcaoMenu = menu(display, event_queue);
    }
    if(opcaoMenu==1 || tipo==1){
      continua = PvP(display, event_queue, posicoes, &rodada);
      tipo=0;
    }
    else if(opcaoMenu==2 || tipo==2){
      continua = PvPc(display, event_queue, posicoes, &rodada);
      tipo=0;
    }
    else if(opcaoMenu==3){
      salvo(posicoes, &rodada, &tipo);
    }
    else{
      break;
    }
  }

  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

  return 0;
}