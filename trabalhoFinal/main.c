#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "peca.h"
#include "menu.h"

int main (){
  int linhas = 6;
  int colunas = 6;
  int rodada=1;

  struct Posicao posicoes[linhas][colunas];

  int i, j, pos=0;
  
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

  al_init();
  al_init_font_addon();
  al_init_image_addon();
  al_install_mouse();

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
  al_register_event_source(event_queue, al_get_mouse_event_source() );
  al_start_timer(timer);


  int opcaoMenu = menu(display, event_queue);

  while(opcaoMenu==1){
    localizaPeca(posicoes);

    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
      break;
    }

    else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){  
      selecionaPeca(event.mouse.x, event.mouse.y, posicoes, &rodada);
      movePeca(event.mouse.x, event.mouse.y, posicoes, &rodada);
    }

    al_draw_bitmap(bg, 0, 0, 0);
    for(i=0; i<linhas; i++){
      for(j=0; j<colunas; j++){
        if(posicoes[i][j].estado==1){
          al_draw_bitmap(peca1, posicoes[i][j].posX, posicoes[i][j].posY, 0);
        }
        else if(posicoes[i][j].estado==2){
          al_draw_bitmap(peca2, posicoes[i][j].posX, posicoes[i][j].posY, 0);
        }
        if(posicoes[i][j].opcao==1){
          al_draw_bitmap(opcao, posicoes[i][j].posX, posicoes[i][j].posY, 0);
        }
        if(posicoes[i][j].selecionada==1){
          al_draw_bitmap(seleciona, posicoes[i][j].posX, posicoes[i][j].posY, 0);
        }
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