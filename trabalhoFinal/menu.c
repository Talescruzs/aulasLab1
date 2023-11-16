#include "peca.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

void criaBt(ALLEGRO_EVENT *event, int posX, int posY, int tamX, int tamY, ALLEGRO_BITMAP * img1, ALLEGRO_BITMAP * img2, int *apertou, int *inbt){
    if(event->type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
        if(event->mouse.x>=posX&&event->mouse.x<=posX+tamX&&event->mouse.y>=posY&&event->mouse.y<=posY+tamY && *inbt==1){
            *apertou=1;
        }
        else{
            *apertou=0;
        }
    }
    else if(event->type==ALLEGRO_EVENT_MOUSE_AXES){ 
        if(event->mouse.x>=posX&&event->mouse.x<=posX+tamX&&event->mouse.y>=posY&&event->mouse.y<=posY+tamY){
            *inbt=1;
        } 
        else{
            *inbt=0;
        }
    }

    if(*inbt==0){
        al_draw_bitmap(img1, posX, posY, 0);
    }
    else{
        al_draw_bitmap(img2, posX, posY, 0);
    }
}
int menu(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue){

    ALLEGRO_BITMAP * bgMenu = al_load_bitmap("./img/menu.jpg");
    ALLEGRO_BITMAP * p2p1 = al_load_bitmap("./img/playerXplayer1.jpg");
    ALLEGRO_BITMAP * p2p2 = al_load_bitmap("./img/playerXplayer2.jpg");
    ALLEGRO_BITMAP * p2c1 = al_load_bitmap("./img/playerXpc1.jpg");
    ALLEGRO_BITMAP * p2c2 = al_load_bitmap("./img/playerXpc2.jpg");
    ALLEGRO_BITMAP * salvo1 = al_load_bitmap("./img/salvos1.jpg");
    ALLEGRO_BITMAP * salvo2 = al_load_bitmap("./img/salvos2.jpg");
    ALLEGRO_BITMAP * historico1 = al_load_bitmap("./img/Historico1.jpg");
    ALLEGRO_BITMAP * historico2 = al_load_bitmap("./img/Historico2.jpg");
    ALLEGRO_BITMAP * ajuda1 = al_load_bitmap("./img/Ajuda1.jpg");
    ALLEGRO_BITMAP * ajuda2 = al_load_bitmap("./img/Ajuda2.jpg");

    int inMenu = 1;
    int inbtPvP=0, apertouPvP=0;
    int inbtPvPc=0, apertouPvPc=0;
    int inbtSalvar=0, apertouSalvar=0;
    int inbtHistorico=0, apertouHistorico=0;
    int inbtAjuda=0, apertouAjuda=0;

    const int menusXpos=275;
    const int menusYpos=200;

    while(inMenu==1){
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(bgMenu, 0, 0, 0);
        criaBt(&event, menusXpos, menusYpos, 300, 150, p2p1, p2p2, &apertouPvP, &inbtPvP);
        criaBt(&event, menusXpos, menusYpos*2, 300, 150, p2c1, p2c2, &apertouPvPc, &inbtPvPc);
        criaBt(&event, menusXpos, menusYpos*3, 300, 150, salvo1, salvo2, &apertouSalvar, &inbtSalvar);
        criaBt(&event, 40, menusYpos*2, 200, 150, historico1, historico2, &apertouHistorico, &inbtHistorico);
        criaBt(&event, menusXpos+340, menusYpos*2, 200, 150, ajuda1, ajuda2, &apertouAjuda, &inbtAjuda);

        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            break;
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            inMenu = 0;
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
    al_destroy_bitmap(historico1);
    al_destroy_bitmap(historico2);
    al_destroy_bitmap(ajuda1);
    al_destroy_bitmap(ajuda2);

    if(apertouPvP==1)
    return 1;
    else if(apertouPvPc==1)
    return 2;
    else if(apertouSalvar==1)
    return 3;
    else if(apertouHistorico==1)
    return 4;
    else if(apertouAjuda==1)
    return 5;

    return 0;
}
