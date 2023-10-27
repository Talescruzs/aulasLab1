#include "peca.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

int menu(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue){

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

    ALLEGRO_BITMAP * bgMenu = al_load_bitmap("./img/menu.jpg");
    ALLEGRO_BITMAP * p2p1 = al_load_bitmap("./img/playerXplayer1.jpg");
    ALLEGRO_BITMAP * p2p2 = al_load_bitmap("./img/playerXplayer2.jpg");
    ALLEGRO_BITMAP * p2c1 = al_load_bitmap("./img/playerXpc1.jpg");
    ALLEGRO_BITMAP * p2c2 = al_load_bitmap("./img/playerXpc2.jpg");
    ALLEGRO_BITMAP * salvo1 = al_load_bitmap("./img/salvos1.jpg");
    ALLEGRO_BITMAP * salvo2 = al_load_bitmap("./img/salvos2.jpg");

    int inMenu = 1;
    int p2p=0;
    int p2c=0;
    int salvo=0;

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
            if(event.mouse.x>menusXpadding&&event.mouse.x<menusXpadding+300 &&event.mouse.y>menusYpadding*2&&event.mouse.y<menusYpadding+350){
                p2c=1;
            } 
            else{
                p2c=0;
            }
            if(event.mouse.x>menusXpadding&&event.mouse.x<menusXpadding+300 &&event.mouse.y>menusYpadding*3&&event.mouse.y<menusYpadding*2+350){
                salvo=1;
            } 
            else{
                salvo=0;
            }
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && (p2c==1||p2p==1||salvo==1)){
            inMenu = 0;
        }

        if(p2p==0){
            al_draw_bitmap(p2p1, menusXpadding, menusYpadding, 0);
        }
        else{
            al_draw_bitmap(p2p2, menusXpadding, menusYpadding, 0);
        }
        if(p2c==0){
            al_draw_bitmap(p2c1, menusXpadding, menusYpadding*2, 0);
        }
        else{
            al_draw_bitmap(p2c2, menusXpadding, menusYpadding*2, 0);
        }
        if(salvo==0){
            al_draw_bitmap(salvo1, menusXpadding, menusYpadding*3, 0);
        }
        else{
            al_draw_bitmap(salvo2, menusXpadding, menusYpadding*3, 0);
        }


        al_flip_display();
    }

    al_destroy_bitmap(bgMenu);
    al_destroy_bitmap(p2p1);
    al_destroy_bitmap(p2p2);
    al_destroy_bitmap(p2c1);
    al_destroy_bitmap(p2c2);
    al_destroy_bitmap(salvo1);
    al_destroy_bitmap(salvo2);

    if(p2p==1)
    return 1;
    else if(p2c==1)
    return 2;
    else if(salvo==1)
    return 3;

    return 0;
}