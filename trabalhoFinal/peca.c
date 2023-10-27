#include "peca.h"
#include <stdio.h>

void selecionaPeca(int posx, int posy, struct Posicao posicoes[6][6], int *rodada){
    int flag=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if((posx>=posicoes[i][j].posX && posx<=posicoes[i][j].posX+60)&&(posy>=posicoes[i][j].posY && posy<=posicoes[i][j].posY+60) && posicoes[i][j].opcao==1){
                flag=1;
            }
        }
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if((posicoes[i][j].estado==1 && *rodada%2==1) || (posicoes[i][j].estado==2 && *rodada%2==0)){
                if((posx>=posicoes[i][j].posX && posx<=posicoes[i][j].posX+60)&&(posy>=posicoes[i][j].posY && posy<=posicoes[i][j].posY+60)){
                    posicoes[i][j].selecionada=1;
                }
                else if(flag==0){
                    posicoes[i][j].selecionada=0;
                }
            }
        }
    }
}

void movePeca(int posx, int posy, struct Posicao posicoes[6][6], int*rodada){
    struct Posicao pecaMov;
    int flag=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(posicoes[i][j].selecionada==1){
                pecaMov = posicoes[i][j];
            }
        }
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(posicoes[i][j].opcao==1){
                if((posx>=posicoes[i][j].posX && posx<=posicoes[i][j].posX+60)&&(posy>=posicoes[i][j].posY && posy<=posicoes[i][j].posY+60)){
                    posicoes[i][j].estado=pecaMov.estado;
                    posicoes[i][j].opcao=0;
                    posicoes[i][j].selecionada=0;
                    *rodada = *rodada+1;
                    flag=1;
                }
            }
        }
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(posicoes[i][j].posX==pecaMov.posX&&posicoes[i][j].posY==pecaMov.posY && flag==1){
                posicoes[i][j].estado=0;
                posicoes[i][j].opcao=0;
                posicoes[i][j].selecionada=0;
                flag=0;
            }
        }
    }
}

void opcaoMovimento(struct Posicao posicoes[6][6], int *linha, int *coluna){
    int posx, posy;
    int flag=0;
    for(int i=0;i<6;i++){
        for(int j=0; j<6;j++){
            if(posicoes[i][j].selecionada==1){
                posx = posicoes[i][j].posX;
                posy = posicoes[i][j].posY;
                *linha=j;
                *coluna=i;
            }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0; j<6;j++){
            if((posicoes[i][j].posX==posx+76||posicoes[i][j].posX==posx-76||posicoes[i][j].posX==posx)&&(posicoes[i][j].posY==posy+85||posicoes[i][j].posY==posy-85||posicoes[i][j].posY==posy)&&(posicoes[i][j].posY!=posy||posicoes[i][j].posX!=posx)&&posicoes[i][j].estado==0){
                posicoes[i][j].opcao=1;
            }
            else{
                posicoes[i][j].opcao=0;
            }
        }
    }
}

void direitaSuperior(struct Posicao posicoes[6][6], int linha, int coluna){
    int limpoDireita=1, limpoCima=1;
    int parouDireita=-1, parouCima=-1;
    for(int i=coluna+1; i<6; i++){
        if(posicoes[i][linha].estado!=0){
            limpoDireita=0;
        }
    }
    for(int i=0; i<linha; i++){
        if(posicoes[coluna][i].estado!=0){
            limpoCima=0;
        }
    }
    if(limpoCima==1){
        for(int i=coluna; i>0; i--){
            if(posicoes[i][linha].estado!=0){
                parouDireita=i;
            }
        }
    }
    if(limpoDireita==1){
        for(int i=0; i<linha; i++){
            if(posicoes[coluna][i].estado!=0){
                limpoCima=0;
            }
        }   
    }
    
    
    if((linha==2||linha==1) && limpoDireita==1 && parouDireita!=-1){
        posicoes[parouDireita][linha].opcao=1;
    }
    if((coluna==3||coluna==4) && limpoCima==1 && parouCima==0){
        posicoes[i][6-coluna-1].opcao=1;
    } 
    
}

void localizaPeca(struct Posicao posicoes[6][6]){
    int linha=-1, coluna=-1;
    opcaoMovimento(posicoes, &linha, &coluna);
    direitaSuperior(posicoes, linha, coluna);

    // for(int i=0;i<6;i++){
    //     for(int j=0; j<6;j++){
    //         direitaSuperior(posicoes, linha, coluna);
    //         // posicoes[i][j].opcao=1;
    //     }
    // }
}