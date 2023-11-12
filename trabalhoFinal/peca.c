#include "peca.h"
#include "ataque.h"
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
void movePeca(int posx, int posy, struct Posicao posicoes[6][6], int *rodada){
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
void localizaPeca(struct Posicao posicoes[6][6]){
    int linha=-1, coluna=-1;
    opcaoMovimento(posicoes, &linha, &coluna);
    if(linha==1||linha==2||coluna==3||coluna==4){
        // printf("direitaSup1\n");
        direitaSuperior(posicoes, linha, coluna);
        // printf("direitaSup2\n");
    }
    if(linha==3||linha==4||coluna==1||coluna==2){
        // printf("esquerdaInf1\n");
        esquerdaInferior(posicoes, linha, coluna);
        // printf("esquerdaInf2\n");
    }

    if(linha==1||linha==2||coluna==1||coluna==2){
        // printf("esquerdaSup1\n");
        esquerdaSuperior(posicoes, linha, coluna);
        // printf("esquerdaSup2\n");
    }
    if(linha==3||linha==4||coluna==3||coluna==4){
        // printf("direitaInf1\n");
        direitaInferior(posicoes, linha, coluna);
        // printf("direitaInf2\n");
    }

}

int movePecaPC(struct Posicao posicoes[6][6], int *rodada, int linha, int coluna){
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(posicoes[i][j].opcao==1&&posicoes[i][j].estado==1){
                movePeca(posicoes[i][j].posX, posicoes[i][j].posY, posicoes, rodada);
                return 1;
            }
        }
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(posicoes[i][j].opcao==1 && j>=linha){
                movePeca(posicoes[i][j].posX, posicoes[i][j].posY, posicoes, rodada);
                return 1;
            }
        }
    }

    // movePeca(posicoes[i+1][j+1].posX, posicoes[i+1][j+1].posY, posicoes, rodada);
    return 0;
}
void computador(struct Posicao posicoes[6][6], int *rodada){
    int i, j, a=0;
    for(i=0; i<6; i++){
        for(j=0; j<6; j++){
            if(posicoes[i][j].estado==2){
                selecionaPeca(posicoes[i][j].posX, posicoes[i][j].posY, posicoes, rodada);
                localizaPeca(posicoes);
                a = movePecaPC(posicoes, rodada, i, j);
                printf("%d  ", i);
                printf("%d\n", j);
                if(a==1){
                    break;
                }
                else{
                    posicoes[i][j].selecionada=0;
                }
            }
        }
        if(a==1){
            break;
        }
    }
    printf("\n");

    // *rodada = *rodada+1;
}