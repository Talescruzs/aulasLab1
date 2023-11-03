#include "peca.h"
#include "menu.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void salvaPartida(struct Posicao posicoes[6][6], int *rodada, int tipo){
    FILE *file;
    file = fopen("save.txt", "w");
    fprintf(file, "partida{\n");
    fprintf(file, "rodada:%d\n", *rodada);
    fprintf(file, "tipo:%d\n", tipo);
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

int PvP(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6]){
    int linhas = 6;
    int colunas = 6;
    int rodada=1;
    int i, j;
    int result = 0, qtd1=0, qtd2=0;
    int inMenu=0;
    ALLEGRO_BITMAP * bg = al_load_bitmap("./img/fundo.png");
    ALLEGRO_BITMAP * cobreFundo = al_load_bitmap("./img/cobreFundo.png");
    ALLEGRO_BITMAP * peca1 = al_load_bitmap("./img/peca1.png");
    ALLEGRO_BITMAP * peca2 = al_load_bitmap("./img/peca2.png");
    ALLEGRO_BITMAP * seleciona = al_load_bitmap("./img/seleciona.png");
    ALLEGRO_BITMAP * opcao = al_load_bitmap("./img/opcao.png");
    ALLEGRO_BITMAP * botao = al_load_bitmap("./img/Salvar1.jpg");

    ALLEGRO_BITMAP * barra = al_load_bitmap("./img/barraMenu.jpg");

    while(1){
        qtd1=0, qtd2=0;
        localizaPeca(posicoes);

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            break;
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
            if(event.mouse.x>=650&&event.mouse.y>=325&&event.mouse.y<=475){
                inMenu=1;
            }
            else if(inMenu==1){
                if(event.mouse.x<=600){
                    inMenu=0;
                }
                else if(event.mouse.x>=625&&event.mouse.x<=825&&event.mouse.y>=200&&event.mouse.y<=350){
                    salvaPartida(posicoes, &rodada, 1);
                }
            }
            else if(inMenu==0){
                selecionaPeca(event.mouse.x, event.mouse.y, posicoes, &rodada);
                movePeca(event.mouse.x, event.mouse.y, posicoes, &rodada);
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
        al_draw_bitmap(botao, 650, 325, 0);
        if(qtd1==0||qtd2==0){
            result = 1;
            break;
        }

        if(inMenu==1){
            al_draw_bitmap(cobreFundo, 0, 0, 0);
            al_draw_bitmap(barra, 600, 0, 0);
            al_draw_bitmap(botao, 625, 200, 0);

        }


        al_flip_display();
    }
    al_destroy_bitmap(bg);
    al_destroy_bitmap(cobreFundo);
    al_destroy_bitmap(peca1);
    al_destroy_bitmap(peca2);
    al_destroy_bitmap(seleciona);
    al_destroy_bitmap(opcao);
    al_destroy_bitmap(botao);
    al_destroy_bitmap(barra);
    return result;
}
int PvPc(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, struct Posicao posicoes[6][6]){
    int linhas = 6;
    int colunas = 6;
    int rodada=1;
    int i, j;
    int result = 0, qtd1=0, qtd2=0;
    int inMenu=0;
    ALLEGRO_BITMAP * bg = al_load_bitmap("./img/fundo.png");
    ALLEGRO_BITMAP * cobreFundo = al_load_bitmap("./img/cobreFundo.png");
    ALLEGRO_BITMAP * peca1 = al_load_bitmap("./img/peca1.png");
    ALLEGRO_BITMAP * peca2 = al_load_bitmap("./img/peca2.png");
    ALLEGRO_BITMAP * seleciona = al_load_bitmap("./img/seleciona.png");
    ALLEGRO_BITMAP * opcao = al_load_bitmap("./img/opcao.png");
    ALLEGRO_BITMAP * botao = al_load_bitmap("./img/Salvar1.jpg");

    ALLEGRO_BITMAP * barra = al_load_bitmap("./img/barraMenu.jpg");

    while(1){
        qtd1=0, qtd2=0;
        localizaPeca(posicoes);

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            break;
        }
        else if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){ 
            if(event.mouse.x>=650&&event.mouse.y>=325&&event.mouse.y<=475){
                inMenu=1;
            }
            else if(inMenu==1){
                if(event.mouse.x<=600){
                    inMenu=0;
                }
                else if(event.mouse.x>=625&&event.mouse.x<=825&&event.mouse.y>=200&&event.mouse.y<=350){
                    salvaPartida(posicoes, &rodada, 2);
                }
            }
            else if(inMenu==0 && rodada%2==1){
                selecionaPeca(event.mouse.x, event.mouse.y, posicoes, &rodada);
                movePeca(event.mouse.x, event.mouse.y, posicoes, &rodada);
            }
        }
        if(rodada%2==0){
            computador(posicoes, &rodada);
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
        al_draw_bitmap(botao, 650, 325, 0);
        if(qtd1==0||qtd2==0){
            result = 1;
            break;
        }

        if(inMenu==1){
            al_draw_bitmap(cobreFundo, 0, 0, 0);
            al_draw_bitmap(barra, 600, 0, 0);
        }


        al_flip_display();
    }
    al_destroy_bitmap(bg);
    al_destroy_bitmap(cobreFundo);
    al_destroy_bitmap(peca1);
    al_destroy_bitmap(peca2);
    al_destroy_bitmap(seleciona);
    al_destroy_bitmap(opcao);
    al_destroy_bitmap(botao);
    al_destroy_bitmap(barra);
    return result;
}

void salvo(struct Posicao posicoes[6][6], int *rodada, int *tipo){
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
            else if(strcmp(realDado, "posx")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                posicoes[linha][coluna].posX = (int)result;
            }
            else if(strcmp(realDado, "posy")==0){
                for(i=tam+1; tLinha[i]!='\0'; i++){
                    dado[count]=tLinha[i];
                    count++;
                }
                char realDado[count];
                for(i=0; i<count; i++){
                    realDado[i]=dado[i];
                }
                long result = strtol(realDado, &teste, 10);
                posicoes[linha][coluna].posY = (int)result;
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