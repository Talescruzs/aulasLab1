#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "peca.h"
#include "menu.h"
#include "historico.h"

int getRodada(){
    FILE *file;
    file = fopen("historico.txt", "r");

    char tLinha[100], dado[10], *teste, *palavra;
    int i, tam=0, count=0, result=0;

    while(fgets(tLinha, 100, file)) {
        tam=0;
        count=0;
        palavra = strchr(tLinha, ':');
        if(palavra!=NULL){
            for(i=0; tLinha[i]!=':'; i++){
                dado[i]=tLinha[i];
                tam++;
            }
            char realDado[tam];
            for(i=0; i<tam; i++){
                realDado[i]=dado[i];
            }
            if(strcmp(realDado, "partida")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                result = (int)strtol(realDado, &teste, 10);
            }
        }
    }

    fclose(file);
    return result;
}
void salvaPartida(struct Posicao posicoes[6][6], int *rodada, int tipo, int64_t tempo){
    FILE *file;
    file = fopen("save.txt", "w");
    fprintf(file, "partida{\n");
    fprintf(file, "rodada:%d\n", *rodada);
    fprintf(file, "tipo:%d\n", tipo);
    fprintf(file, "tempo:%ld\n", tempo);
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            fprintf(file, "%dX%d{\n", i, j);
            fprintf(file, "posx:%d\n", posicoes[i][j].posX);
            fprintf(file, "posy:%d\n", posicoes[i][j].posY);
            fprintf(file, "estado:%d\n", posicoes[i][j].estado);
            fprintf(file, "}\n");
        }
    }
    fprintf(file, "}");
    fclose(file);
}
int menuLateral(ALLEGRO_EVENT *event, int *inMenu, struct Posicao posicoes[6][6], int *rodada, int tipo, int * result, int *inbtMenu, int *inbtSalvar, int *inbtDica, ALLEGRO_TIMER* timer, int*qtdDica){
    ALLEGRO_BITMAP * botaoSalva1 = al_load_bitmap("./img/Salvar1.jpg");
    ALLEGRO_BITMAP * botaoSalva2 = al_load_bitmap("./img/Salvar2.jpg");
    ALLEGRO_BITMAP * botaoMenu1 = al_load_bitmap("./img/voltaMenu1.jpg");
    ALLEGRO_BITMAP * botaoMenu2 = al_load_bitmap("./img/voltaMenu2.jpg");
    ALLEGRO_BITMAP * botaoDica1 = al_load_bitmap("./img/dica1.jpg");
    ALLEGRO_BITMAP * botaoDica2 = al_load_bitmap("./img/dica2.jpg");
    ALLEGRO_BITMAP * barra = al_load_bitmap("./img/barraMenu.jpg");
    ALLEGRO_BITMAP * cobreFundo = al_load_bitmap("./img/cobreFundo.png");

    int apertouDica = 0;
    int apertouVoltaMenu = 0;
    int apertouSalva = 0;
    int deuDica = 0;

    if(*inMenu==0){
        criaBt(event, 650, 325, 150, 150, botaoMenu1, botaoMenu2, inMenu, inbtMenu);
    }
    else{
        al_draw_bitmap(cobreFundo, 0, 0, 0);
        al_draw_bitmap(barra, 600, 0, 0);
        criaBt(event, 625, 100, 150, 150, botaoSalva1, botaoSalva2, &apertouSalva, inbtSalvar);
        if(apertouSalva==1){
            salvaPartida(posicoes, rodada, tipo, al_get_timer_count(timer)/30);
        }
        criaBt(event, 625, 300, 150, 150, botaoMenu1, botaoMenu2, &apertouVoltaMenu, inbtMenu);
        if(apertouVoltaMenu==1){
            *result = 1;
            return -1;
        }
        criaBt(event, 625, 500, 150, 150, botaoDica1, botaoDica2, &apertouDica, inbtDica);
        if(apertouDica==1){
            deuDica = dica(posicoes, qtdDica, tipo, rodada);
        }
    }

    if( event->type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
        return -1;
    }
    else if(event->type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
        if(*inMenu==1){
            al_stop_timer(timer);
            if(event->mouse.x<=600 || deuDica==1){
                *inMenu=0;
                al_resume_timer(timer);
            }
        }
    }

    al_destroy_bitmap(botaoSalva1);
    al_destroy_bitmap(botaoSalva2);
    al_destroy_bitmap(botaoMenu1);
    al_destroy_bitmap(botaoMenu2);
    al_destroy_bitmap(botaoDica1);
    al_destroy_bitmap(botaoDica2);
    al_destroy_bitmap(barra);
    al_destroy_bitmap(cobreFundo);

    return 0;
}
int partida(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6], int *rodada, ALLEGRO_FONT* font, int64_t *time, int tipo){
    int linhas = 6;
    int colunas = 6;
    int i, j;
    int result = 0, qtd1=0, qtd2=0;
    int inMenu=0;
    int inbtSalvar=0, inbtMenu=0, inbtDica=0;
    int menuInput=0;
    char rodadaStr[15];
    char tempoStr[15];
    char qtdDicaStr[15];
    int continua=1;
    int qtdDica1=0, qtdDica2=0;
    int deuDica=0, testeDica=0;
    int lado =0;

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    al_set_timer_count(timer, (*time)*30);

    ALLEGRO_BITMAP * bg = al_load_bitmap("./img/fundo.png");
    ALLEGRO_BITMAP * peca1 = al_load_bitmap("./img/peca1.png");
    ALLEGRO_BITMAP * peca2 = al_load_bitmap("./img/peca2.png");
    ALLEGRO_BITMAP * seleciona = al_load_bitmap("./img/seleciona.png");
    ALLEGRO_BITMAP * opcao = al_load_bitmap("./img/opcao.png");

    while(menuInput!=-1){
        int64_t tempo = al_get_timer_count(timer)/30;
        if(*rodada%2==1)
        lado=1;
        else
        lado=2;

        qtd1=0, qtd2=0;
        if(!deuDica){
            localizaPeca(posicoes, lado); 
        }
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if(tipo==1){
            if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
                break;
            }
            else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
                if(inMenu==0){
                    selecionaPeca(event.mouse.x, event.mouse.y, posicoes, rodada);
                    movePeca(event.mouse.x, event.mouse.y, posicoes, rodada);
                    deuDica=0;
                }
            }
        }
        else{
            if(*rodada%2==0){
                continua = computador(posicoes, rodada);
                if(continua==0){
                    addHistorico(rodada, 0, tipo, tempo);
                    result = 1;
                    break; 
                }
            }
            else{
                if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
                    break;
                }
                else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
                    if(inMenu==0){
                        selecionaPeca(event.mouse.x, event.mouse.y, posicoes, rodada);
                        movePeca(event.mouse.x, event.mouse.y, posicoes, rodada);
                        deuDica=0;
                    }
                }
            }
        }

        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(bg, 0, 0, 0);

        for(i=0; i<linhas; i++){
            for(j=0; j<colunas; j++){
                if(posicoes[i][j].estado==1){
                    al_draw_bitmap(peca1, posicoes[i][j].posX, posicoes[i][j].posY, 0);
                    qtd1++;
                }
                else if(posicoes[i][j].estado==2){
                    al_draw_bitmap(peca2, posicoes[i][j].posX, posicoes[i][j].posY, 0);
                    qtd2++;
                }
                if(posicoes[i][j].opcao==1){
                    al_draw_bitmap(opcao, posicoes[i][j].posX, posicoes[i][j].posY, 0);
                }
                if(posicoes[i][j].selecionada==1){
                    al_draw_bitmap(seleciona, posicoes[i][j].posX, posicoes[i][j].posY, 0);
                }
            }
        }
        if(qtd1==0||qtd2==0){
            result = 1;
            if(qtd1==0){
                addHistorico(rodada, 2, tipo, tempo);                
            }
            else{
                addHistorico(rodada, 1, tipo, tempo);                
            }
            break;
        }
        

        if(tipo==1){
            if(*rodada%2==1){
                testeDica = qtdDica1;
                menuInput = menuLateral(&event, &inMenu, posicoes, rodada, tipo, &result, &inbtMenu, &inbtSalvar, &inbtDica, timer, &qtdDica1);
                if(testeDica!=qtdDica1){
                    deuDica=1;
                }
            }
            else{
                testeDica = qtdDica2;
                menuInput = menuLateral(&event, &inMenu, posicoes, rodada, tipo, &result, &inbtMenu, &inbtSalvar, &inbtDica, timer, &qtdDica2);
                if(testeDica!=qtdDica2){
                    deuDica=1;
                }
            }
            snprintf(qtdDicaStr, 15, "Dicas 1: %d", qtdDica1);
            al_draw_text(font, al_map_rgb(0, 0, 0), 670, 20, 0, qtdDicaStr);
            snprintf(qtdDicaStr, 15, "Dicas 2: %d", qtdDica2);
            al_draw_text(font, al_map_rgb(0, 0, 0), 670, 50, 0, qtdDicaStr);
            snprintf(rodadaStr, 15, "Rodada %d", *rodada);
            snprintf(tempoStr, 15, "Tempo: %ld", tempo);
            al_draw_text(font, al_map_rgb(0, 0, 0), 670, 770, 0, rodadaStr);
            al_draw_text(font, al_map_rgb(0, 0, 0), 670, 740, 0, tempoStr);
        }
        else{
            testeDica = qtdDica1;
            menuInput = menuLateral(&event, &inMenu, posicoes, rodada, tipo, &result, &inbtMenu, &inbtSalvar, &inbtDica, timer, &qtdDica1);
            if(testeDica!=qtdDica1){
                deuDica=1;
            }
            snprintf(qtdDicaStr, 15, "Dicas: %d", qtdDica1);
            al_draw_text(font, al_map_rgb(0, 0, 0), 670, 20, 0, qtdDicaStr);
            snprintf(rodadaStr, 15, "Rodada %d", *rodada);
            snprintf(tempoStr, 15, "Tempo: %ld", tempo);
            al_draw_text(font, al_map_rgb(0, 0, 0), 670, 770, 0, rodadaStr);
            al_draw_text(font, al_map_rgb(0, 0, 0), 670, 740, 0, tempoStr);
        }


        al_flip_display();
    }
    al_destroy_bitmap(bg);
    al_destroy_bitmap(peca1);
    al_destroy_bitmap(peca2);
    al_destroy_bitmap(seleciona);
    al_destroy_bitmap(opcao);

    return result;
}
void salvo(struct Posicao posicoes[6][6], int *rodada, int *tipo, ALLEGRO_FONT* font, int64_t *tempo){
    FILE *file;
    file = fopen("save.txt", "r");

    char tLinha[100], dado[10], *teste, *palavra;
    int linha=-1, coluna=-1, i, tam=0, count=0;

    while(fgets(tLinha, 100, file)) {
        tam=0;
        count=0;
        palavra = strchr(tLinha, ':');
        if(palavra!=NULL){
            for(i=0; tLinha[i]!=':'; i++){
                dado[i]=tLinha[i];
                tam++;
            }
            char realDado[tam];
            for(i=0; i<tam; i++){
                realDado[i]=dado[i];
            }
            if(strcmp(realDado, "rodada")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                *rodada = (int)result;
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
                *tipo = (int)result;
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
                *tempo = (int64_t)result;
            }
            else if(strcmp(realDado, "estado")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                posicoes[linha][coluna].estado = (int)result;
            }
        }
        palavra = strchr(tLinha, 'X');
        if(palavra!=NULL){
            linha = *(palavra-1)-'0';
            coluna = *(palavra+1)-'0';
        }
    }

    // Close the file
    fclose(file);
}