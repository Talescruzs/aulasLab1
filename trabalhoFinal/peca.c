#include "peca.h"

void selecionaPeca(int posx, int posy, struct Peca pecas[], int npecas){
    for(int i=0; i<npecas; i++){
        if(pecas[i].time==1){
            if((posx>=pecas[i].posX && posx<=pecas[i].posX+60)&&(posy>=pecas[i].posY && posy<=pecas[i].posY+60)){
                pecas[i].selecionada=1;
            }
            else{
                pecas[i].selecionada=0;
            }
        }
    }
}

void localizaPeca(struct Posicao posicoes[6][6], struct Peca pecas[], int npecas){
    int posx, posy;
    for(int i=0; i<npecas; i++){
        if(pecas[i].selecionada==1){
            posx = pecas[i].posX;
            posy = pecas[i].posY;
        }
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            for(int k=0; k<npecas;k++){
                if(posicoes[i][j].posX == pecas[k].posX && posicoes[i][j].posY == pecas[k].posY){
                        posicoes[i][j].estado = 1;
                }
            }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0; j<6;j++){
            if((posicoes[i][j].posX==posx+76||posicoes[i][j].posX==posx-76||posicoes[i][j].posX==posx)&&(posicoes[i][j].posY==posy+85||posicoes[i][j].posY==posy-85||posicoes[i][j].posY==posy)&&(posicoes[i][j].posY!=posy||posicoes[i][j].posX!=posx)&&posicoes[i][j].estado!=1){
                posicoes[i][j].estado=2;
            }
            else{
                posicoes[i][j].estado=0;
            }
        }
    }
}