#include "peca.h"

int selecionaPeca(int posx, int posy, struct Peca pecas[], int npecas){
    for(int i=0; i<npecas; i++){
        if(pecas[i].time==1){
            if((posx>=pecas[i].posX && posx<=pecas[i].posX+60)&&(posy>=pecas[i].posY && posy<=pecas[i].posY+60)){
                return i;
            }
        }
    }
    return -1;
}