#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "peca.h"
#include "menu.h"
#include "partidas.h"
#include "historico.h"

int main (){
  int linhas = 6;
  int colunas = 6;
  int rodada=1;
  int dica1=0,dica2=0;
  int tipo=0;

  struct Posicao posicoes[linhas][colunas];

  int i, j, pos=0;

  al_init();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();
  al_install_mouse();

  ALLEGRO_DISPLAY * display = al_create_display(850, 806);
  al_set_window_position(display, 100, 100);
  al_set_window_title(display, "surakarta");

  ALLEGRO_FONT* font = al_load_font("./font.ttf", 30, 0);;

  ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_mouse_event_source() );
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_start_timer(timer);

  int continua=1;
  int64_t tempo=0;

  while(continua==1){
    if(tipo==3){
      salvo(posicoes, &rodada, &tipo, font, &tempo, &dica1, &dica2);
    }
    else{
      for(i=0; i<colunas; i++){
        for(j=0; j<linhas; j++){
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
      rodada=1;
      dica1=0;
      dica2=0;
      tempo=0;
      tipo = menu(display, event_queue);
    }
    if(tipo==1 || tipo==2){
      continua = partida(display, event_queue, posicoes, &rodada, font, &tempo, &tipo, &dica1, &dica2);
      if(continua==2){
        continuaMenu(display, event_queue, &tipo, &rodada, &dica1, &dica2);
        continua=1;
      }
    }
    else if(tipo==4){
      getHistorico(display, event_queue, font, &continua);
      tipo=0;
    }
    else if(tipo==5){
      telaAjuda(display, event_queue, font, &continua, 1);
      tipo=0;
    }
    if(tipo==-1){
      break;
    }

  }

  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

  return 0;
}