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
void verificaCaminhoDireita(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoDireita){
    *limpoDireita=1;
    for(int i=coluna+1; i<6; i++){
        if(posicoes[i][linha].estado!=0&&posicoes[i][linha].selecionada==0){
            *limpoDireita=0;
        }
    }
}
void verificaCaminhoEsquerda(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoEsquerda){
    *limpoEsquerda=1;
    for(int i=0; i<coluna; i++){
        if(posicoes[i][linha].estado!=0&&posicoes[i][linha].selecionada==0){
            *limpoEsquerda=0;
        }
    }
}
void verificaCaminhoBaixo(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoBaixo){
    *limpoBaixo=1;
    for(int i=linha+1; i<6; i++){
        if(posicoes[coluna][i].estado!=0&&posicoes[i][linha].selecionada==0){
            *limpoBaixo=0;
        }
    }
}
void verificaCaminhoCima(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoCima){
    *limpoCima=1;
    for(int i=0; i<linha; i++){
        if(posicoes[coluna][i].estado!=0&&posicoes[i][linha].selecionada==0){
            *limpoCima=0;
        }
    }
}

int varreCimaBaixo(struct Posicao posicoes[6][6], int coluna, int time){
    for(int i=0; i<6; i++){
        if(posicoes[coluna][i].estado!=time && posicoes[coluna][i].estado!=0){
            return i;
        }
        else if(posicoes[coluna][i].estado==time && posicoes[coluna][i].selecionada!=1){
            return -1;
        }
    }
    return 6;
}
int varreBaixoCima(struct Posicao posicoes[6][6], int coluna, int time){
    for(int i=5; i>=0; i--){
        if(posicoes[coluna][i].estado!=time && posicoes[coluna][i].estado!=0){
            return i;
        }
        else if(posicoes[coluna][i].estado==time && posicoes[coluna][i].selecionada!=1){
            return -1;
        }
    }
    return 6;
}
int varreDireitaEsquerda(struct Posicao posicoes[6][6], int linha, int time){
    for(int i=5; i>=0; i--){
        if(posicoes[i][linha].estado!=time && posicoes[i][linha].estado!=0){
            return i;
        }
        else if(posicoes[i][linha].estado==time && posicoes[i][linha].selecionada!=1){
            return -1;
        }
    }
    return 6;
}
int varreEsquerdaDireita(struct Posicao posicoes[6][6], int linha, int time){
    for(int i=0; i<6; i++){
        if(posicoes[i][linha].estado!=time && posicoes[i][linha].estado!=0){
            return i;
        }
        else if(posicoes[i][linha].estado==time && posicoes[i][linha].selecionada!=1){
            return -1;
        }
    }
    return 6;
}

void direitaSuperior(struct Posicao posicoes[6][6], int linha, int coluna){
    int limpoDireita=0, limpoCima=0;
    int colunaOpcao, linhaOpcao;

    if(linha==1||linha==2){
        verificaCaminhoDireita(posicoes, linha, coluna, &limpoDireita);
    }
    if(coluna==3||coluna==4){
        verificaCaminhoCima(posicoes, linha, coluna, &limpoCima);
    }
    if(limpoCima==1){
        colunaOpcao=varreDireitaEsquerda(posicoes, 5-coluna, posicoes[coluna][linha].estado);
        if(colunaOpcao>=0&&colunaOpcao<6){
            posicoes[colunaOpcao][5-coluna].opcao=1;
        }
    }
    if(limpoDireita==1){
        linhaOpcao=varreCimaBaixo(posicoes, 5-linha, posicoes[coluna][linha].estado);
        if(linhaOpcao>=0&&linhaOpcao<6){
            posicoes[5-linha][linhaOpcao].opcao=1;
        }
    }
}
void esquerdaSuperior(struct Posicao posicoes[6][6], int linha, int coluna){
    int limpoEsquerda=0, limpoCima=0;
    int colunaOpcao, linhaOpcao;

    if(linha==1||linha==2){
        verificaCaminhoEsquerda(posicoes, linha, coluna, &limpoEsquerda);
    }
    if(coluna==1||coluna==2){
        verificaCaminhoCima(posicoes, linha, coluna, &limpoCima);
    }
    if(limpoCima==1){
        colunaOpcao=varreEsquerdaDireita(posicoes, coluna, posicoes[coluna][linha].estado);
        if(colunaOpcao>=0&&colunaOpcao<6){
            posicoes[colunaOpcao][coluna].opcao=1;
        }
    }
    if(limpoEsquerda==1){
        linhaOpcao=varreCimaBaixo(posicoes, linha, posicoes[coluna][linha].estado);
        if(linhaOpcao>=0&&linhaOpcao<6){
            posicoes[linha][linhaOpcao].opcao=1;
        }
    }
}
void direitaInferior(struct Posicao posicoes[6][6], int linha, int coluna){
    int limpoDireita=0, limpoBaixo=0;
    int colunaOpcao, linhaOpcao;

    if(linha==3||linha==4){
        verificaCaminhoDireita(posicoes, linha, coluna, &limpoDireita);
    }
    if(coluna==3||coluna==4){
        verificaCaminhoBaixo(posicoes, linha, coluna, &limpoBaixo);
    }
    if(limpoBaixo==1){
        colunaOpcao=varreDireitaEsquerda(posicoes, coluna, posicoes[coluna][linha].estado);
        if(colunaOpcao>=0&&colunaOpcao<6){
            posicoes[colunaOpcao][coluna].opcao=1;
        }
    }
    if(limpoDireita==1){
        linhaOpcao=varreBaixoCima(posicoes, linha, posicoes[coluna][linha].estado);
        if(linhaOpcao>=0&&linhaOpcao<6){
            posicoes[linha][linhaOpcao].opcao=1;
        }
    }
}
void esquerdaInferior(struct Posicao posicoes[6][6], int linha, int coluna){
    int limpoEsquerda=0, limpoBaixo=0;
    int colunaOpcao, linhaOpcao;

    if(linha==3||linha==4){
        verificaCaminhoEsquerda(posicoes, linha, coluna, &limpoEsquerda);
    }
    if(coluna==1||coluna==2){
        verificaCaminhoBaixo(posicoes, linha, coluna, &limpoBaixo);
    }
    if(limpoBaixo==1){
        colunaOpcao=varreEsquerdaDireita(posicoes, 5-coluna, posicoes[coluna][linha].estado);
        if(colunaOpcao>=0&&colunaOpcao<6){
            posicoes[colunaOpcao][5-coluna].opcao=1;
        }
    }
    if(limpoEsquerda==1){
        linhaOpcao=varreBaixoCima(posicoes, 5-linha, posicoes[coluna][linha].estado);
        if(linhaOpcao>=0&&linhaOpcao<6){
            posicoes[5-linha][linhaOpcao].opcao=1;
        }
    }
}


void localizaPeca(struct Posicao posicoes[6][6]){
    int linha=-1, coluna=-1;
    opcaoMovimento(posicoes, &linha, &coluna);
    if(linha==1||linha==2||coluna==3||coluna==4){
        direitaSuperior(posicoes, linha, coluna);
    }
    else if(linha==3||linha==4||coluna==1||coluna==2){
        esquerdaInferior(posicoes, linha, coluna);
    }

    if(linha==1||linha==2||coluna==1||coluna==2){
        esquerdaSuperior(posicoes, linha, coluna);
    }
    else if(linha==3||linha==4||coluna==3||coluna==4){
        direitaInferior(posicoes, linha, coluna);
    }

}