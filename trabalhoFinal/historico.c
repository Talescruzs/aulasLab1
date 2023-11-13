#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include "historico.h"
#include "partidas.h"

void getHistorico(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, ALLEGRO_FONT* font, int *continua){
    FILE *file;
    file = fopen("historico.txt", "r");
    ALLEGRO_BITMAP * bgMenu = al_load_bitmap("./img/menu.jpg");
    ALLEGRO_BITMAP * botaoMenu1 = al_load_bitmap("./img/voltaMenu1.jpg");
    ALLEGRO_BITMAP * botaoMenu2 = al_load_bitmap("./img/voltaMenu2.jpg");


    char tLinha[100], dado[15], *teste, *palavra;
    int linha=-1, i, tam=0, count=0;
    int rodada, partida, tipo, vencedor, tempo;
    int nHistorico=0;
    char rodadaStr[15], partidaStr[15], tipoStr[15], vencedorStr[15], tempoStr[15];
    struct Historico historico[getRodada()];

    while(fgets(tLinha, 100, file)) {
        tam=0;
        count=0;
        palavra = strchr(tLinha, ':');
        if(palavra!=NULL){
            for(i=0; tLinha[i]!=':'; i++){
                dado[i]=tLinha[i];
                tam++;
            }
            dado[tam]='\0';
            char realDado[tam];
            for(i=0; i<tam; i++){
                realDado[i]=dado[i];
            }
            realDado[tam]='\0';
            if(strcmp(realDado, "partida")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                partida = (int)result;
            }
            else if(strcmp(realDado, "rodada")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                rodada = (int)result;
            }
            else if(strcmp(realDado, "tipo")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                tipo = (int)result;
            }
            else if(strcmp(realDado, "tempo")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                tempo = (int)result;
            }
            else if(strcmp(realDado, "vencedor")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                vencedor = (int)result;
            }
            // printf("%s\n", realDado);
        }
        else{
            historico[nHistorico].rodada = rodada;
            historico[nHistorico].partida = partida;
            historico[nHistorico].tipo = tipo;
            historico[nHistorico].vencedor = vencedor;
            historico[nHistorico].tempo = tempo;
            nHistorico++;
        }
    }

    // Close the file
    fclose(file);
    int inbtMenu=0;
    while(1){
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(bgMenu, 0, 0, 0);
        for(i=0; i<nHistorico; i++){
            snprintf(rodadaStr, 15, "%d", historico[i].rodada);
            snprintf(partidaStr, 15, "%d", historico[i].partida);
            snprintf(tempoStr, 15, "%d", historico[i].tempo);
            al_draw_text(font, al_map_rgb(0, 0, 0), 20, 130, 0, "Partida");
            al_draw_text(font, al_map_rgb(0, 0, 0), 200, 130, 0, "Rodadas");
            al_draw_text(font, al_map_rgb(0, 0, 0), 400, 130, 0, "Tipo");
            al_draw_text(font, al_map_rgb(0, 0, 0), 530, 130, 0, "Vencedor");
            al_draw_text(font, al_map_rgb(0, 0, 0), 720, 130, 0, "Tempo");
            if(historico[i].tipo==1){
                strcpy(tipoStr, "PxP");
            }
            else{
                strcpy(tipoStr, "PxPC");
            }

            if(historico[i].vencedor==1){
                strcpy(vencedorStr, "Player1");
            }
            else if(historico[i].tipo==1){
                strcpy(vencedorStr, "Player2");
            }
            else{
                strcpy(vencedorStr, "Computador");
            }
            al_draw_text(font, al_map_rgb(0, 0, 0), 70, 200+(50*i), 0, partidaStr);
            al_draw_text(font, al_map_rgb(0, 0, 0), 250, 200+(50*i), 0, rodadaStr);
            al_draw_text(font, al_map_rgb(0, 0, 0), 410, 200+(50*i), 0, tipoStr);
            al_draw_text(font, al_map_rgb(0, 0, 0), 540, 200+(50*i), 0, vencedorStr);
            al_draw_text(font, al_map_rgb(0, 0, 0), 750, 200+(50*i), 0, tempoStr);

        }
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            *continua=0;
            break;
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
            if(event.mouse.x>=650&&event.mouse.y>=660){
                break;
            }
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_AXES){ 
            if(event.mouse.x>=650&&event.mouse.y>=660){
                inbtMenu=1;
            } 
            else{
                inbtMenu=0;
            }
        }

        if(inbtMenu==0){
            al_draw_bitmap(botaoMenu1, 650, 660, 0);
        }
        else if(inbtMenu==1){
            al_draw_bitmap(botaoMenu2, 650, 660, 0);
        }

        al_flip_display();

    }
    al_destroy_bitmap(bgMenu);
    al_destroy_bitmap(botaoMenu1);
    al_destroy_bitmap(botaoMenu2);
}

void addHistorico(int *rodada, int vencedor, int tipo, int64_t tempo){
    int ultimaPartida = 1;
    ultimaPartida = getRodada()+1;
    FILE *file;
    file = fopen("historico.txt", "a");
    fprintf(file, "partida:%d\n", ultimaPartida);
    fprintf(file, "rodada:%d\n", *rodada);
    fprintf(file, "tipo:%d\n", tipo);
    fprintf(file, "vencedor:%d\n", vencedor);
    fprintf(file, "tempo:%ld\n", tempo);
    fprintf(file, "\n");
    fclose(file);
}
void telaAjuda(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, ALLEGRO_FONT* font, int *continua, int parte){
    FILE *file;
    char nomeArquivo[20];
    ALLEGRO_BITMAP * bgMenu = al_load_bitmap("./img/menu.jpg");
    ALLEGRO_BITMAP * botaoMenu1 = al_load_bitmap("./img/voltaMenu1.jpg");
    ALLEGRO_BITMAP * botaoMenu2 = al_load_bitmap("./img/voltaMenu2.jpg");

    ALLEGRO_BITMAP * prox1 = al_load_bitmap("./img/prox1.jpg");
    ALLEGRO_BITMAP * ant1 = al_load_bitmap("./img/ant1.jpg");

    if(parte>0&&parte<4){
        snprintf(nomeArquivo, 20, "ajuda%d.txt", parte);
        file = fopen(nomeArquivo, "r");

        char tLinha[100][100];
        char tam=0, i;

        while(fgets(tLinha[tam], 100, file)) {
            for(i=0; tLinha[tam][i]!='\0'; i++){
                if(tLinha[tam][i]=='\n'){
                    tLinha[tam][i]='\0';
                }
            }
            tam++;
        }
        // Close the file
        fclose(file);
        int inbtMenu=0;
        int inbtProx=0;
        int inbtAnt=0;
        while(1){
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue, &event);

            al_clear_to_color(al_map_rgb(255,255,255));
            al_draw_bitmap(bgMenu, 0, 0, 0);
            for(i=0; i<tam; i++){
                al_draw_text(font, al_map_rgb(0, 0, 0), 20, 130+(30*i), 0, tLinha[i]);

            }
            if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
                *continua=0;
                break;
            }
            else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
                if(event.mouse.x>=330&&event.mouse.x<=530&&event.mouse.y>=660){
                    break;
                }
                if(event.mouse.x>=650&&event.mouse.y>=660){
                    telaAjuda(display, event_queue, font, continua, parte+1);
                    break;
                }
                if(event.mouse.x>=0&&event.mouse.x<=200&&event.mouse.y>=660){
                    telaAjuda(display, event_queue, font, continua, parte-1);
                    break;
                }
            }
            else if(event.type==ALLEGRO_EVENT_MOUSE_AXES){ 
                if(event.mouse.x>=330&&event.mouse.x<=530&&event.mouse.y>=660){
                    inbtMenu=1;
                } 
                else{
                    inbtMenu=0;
                }
                if(event.mouse.x>=650&&event.mouse.y>=660){
                    inbtProx=1;
                } 
                else{
                    inbtProx=0;
                }
                if(event.mouse.x>=0&&event.mouse.x>=200&&event.mouse.y>=660){
                    inbtAnt=1;
                } 
                else{
                    inbtAnt=0;
                }
            }

            if(inbtMenu==0){
                al_draw_bitmap(botaoMenu1, 330, 660, 0);
            }
            else if(inbtMenu==1){
                al_draw_bitmap(botaoMenu2, 330, 660, 0);
            }
            if(inbtProx==0){
                al_draw_bitmap(prox1, 650, 660, 0);
            }
            else if(inbtProx==1){
                al_draw_bitmap(prox1, 650, 660, 0);
            }
            if(inbtAnt==0){
                al_draw_bitmap(ant1, 0, 660, 0);
            }
            else if(inbtAnt==1){
                al_draw_bitmap(ant1, 0, 660, 0);
            }

            al_flip_display();
        }
    }
    al_destroy_bitmap(bgMenu);
    al_destroy_bitmap(botaoMenu1);
    al_destroy_bitmap(botaoMenu2);
}