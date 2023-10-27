#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "peca.h"

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
  ALLEGRO_BITMAP * bgMenu = al_load_bitmap("./img/menu.jpg");

  ALLEGRO_BITMAP * p2p1 = al_load_bitmap("./img/playerXplayer1.jpg");
  ALLEGRO_BITMAP * p2p2 = al_load_bitmap("./img/playerXplayer2.jpg");
  ALLEGRO_BITMAP * p2c1 = al_load_bitmap("./img/playerXpc1.jpg");
  ALLEGRO_BITMAP * p2c2 = al_load_bitmap("./img/playerXpc2.jpg");

  ALLEGRO_BITMAP * peca1 = al_load_bitmap("./img/peca1.png");
  ALLEGRO_BITMAP * peca2 = al_load_bitmap("./img/peca2.png");
  ALLEGRO_BITMAP * seleciona = al_load_bitmap("./img/seleciona.png");
  ALLEGRO_BITMAP * opcao = al_load_bitmap("./img/opcao.png");

  ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_mouse_event_source() );
  al_start_timer(timer);

  int inMenu = 1;
  int p2p=0;
  int p2c=0;

  const int menusXpadding=200;
  const int menusYpadding=200;

  while(inMenu==1){

    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    al_draw_bitmap(bgMenu, 0, 0, 0);

    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
      break;
    }
    else if(event.type==ALLEGRO_EVENT_MOUSE_AXES){ 
      if(event.mouse.x>menusXpadding&&event.mouse.x<menusXpadding+300 &&event.mouse.y>menusYpadding&&event.mouse.y<menusYpadding+150){
        p2p=1;
      } 
      else{
        p2p=0;
      }
      if(event.mouse.x>menusXpadding&&event.mouse.x<menusXpadding+300 &&event.mouse.y>menusYpadding+200&&event.mouse.y<menusYpadding+350){
        p2c=1;
      } 
      else{
        p2c=0;
      }
    }
    else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (p2c==1||p2p==1)){
      inMenu = 0;
    }

    if(p2p==0){
      al_draw_bitmap(p2p1, menusXpadding, menusYpadding, 0);
    }
    else{
      al_draw_bitmap(p2p2, menusXpadding, menusYpadding, 0);
    }
    if(p2c==0){
      al_draw_bitmap(p2c1, menusXpadding, menusYpadding+200, 0);
    }
    else{
      al_draw_bitmap(p2c2, menusXpadding, menusYpadding+200, 0);
    }


    al_flip_display();
  }

  while(true){
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
  al_destroy_bitmap(bgMenu);
  al_destroy_bitmap(p2p1);
  al_destroy_bitmap(p2p2);
  al_destroy_bitmap(p2c1);
  al_destroy_bitmap(p2c2);
  al_destroy_bitmap(peca1);
  al_destroy_bitmap(peca2);
  al_destroy_bitmap(seleciona);
  al_destroy_bitmap(opcao);
  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

  return 0;
}