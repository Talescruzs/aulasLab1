#include "ataque.h"
#include "peca.h"
#include <stdio.h>

//VERIFICACOES:
void verificaCaminhoDireita(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoDireita){
    *limpoDireita=1;
    for(int i=coluna+1; i<6; i++){
        if(posicoes[i][linha].estado!=0&&posicoes[i][linha].selecionada==0){
            *limpoDireita=0;
        }
    }
    // if(*limpoDireita==1){
    //     printf("LimpoDireita\n");
    // }
}
void verificaCaminhoEsquerda(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoEsquerda){
    *limpoEsquerda=1;
    for(int i=0; i<coluna; i++){
        if(posicoes[i][linha].estado!=0&&posicoes[i][linha].selecionada==0){
            *limpoEsquerda=0;
        }
    }
    // if(*limpoEsquerda==1){
    //     printf("LimpoEsquerda\n");
    // }
}
void verificaCaminhoBaixo(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoBaixo){
    *limpoBaixo=1;
    for(int i=linha+1; i<6; i++){
        if(posicoes[coluna][i].estado!=0&&posicoes[coluna][i].selecionada==0){
            *limpoBaixo=0;
        }
    }
    // if(*limpoBaixo==1){
    //     printf("LimpoBaixo\n");
    // }
}
void verificaCaminhoCima(struct Posicao posicoes[6][6], int linha, int coluna, int *limpoCima){
    *limpoCima=1;
    for(int i=0; i<linha; i++){
        if(posicoes[coluna][i].estado!=0&&posicoes[coluna][i].selecionada==0){
            *limpoCima=0;
        }
    }
    // if(*limpoCima==1){
    //     printf("LimpoCima\n");
    // }
}

//VARREDURAS:
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

//ATAQUES:
void direitaSuperior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time){
    int limpoDireita=0, limpoCima=0;
    int colunaOpcao, linhaOpcao;
    if(index<4){
        if(linha==1||linha==2){
            verificaCaminhoDireita(posicoes, linha, coluna, &limpoDireita);
        }
        if(coluna==3||coluna==4){
            verificaCaminhoCima(posicoes, linha, coluna, &limpoCima);
        }
        if(limpoCima==1){
            colunaOpcao=varreDireitaEsquerda(posicoes, 5-coluna, time);
            if(colunaOpcao>=0&&colunaOpcao<6){
                posicoes[colunaOpcao][5-coluna].opcao=1;
            }
            else if(colunaOpcao==6){
                esquerdaSuperior(posicoes, 5-coluna, 0, index+1, time);
            }
        }
        if(limpoDireita==1){
            linhaOpcao=varreCimaBaixo(posicoes, 5-linha, time);
            if(linhaOpcao>=0&&linhaOpcao<6){
                posicoes[5-linha][linhaOpcao].opcao=1;
            }
            else if(linhaOpcao==6){
                direitaInferior(posicoes, 0, 5-linha, index+1, time);
            }
        }
    }
}
void esquerdaSuperior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time){
    int limpoEsquerda=0, limpoCima=0;
    int colunaOpcao, linhaOpcao;

    if(index<4){
        if(linha==1||linha==2){
            verificaCaminhoEsquerda(posicoes, linha, coluna, &limpoEsquerda);
        }
        if(coluna==1||coluna==2){
            verificaCaminhoCima(posicoes, linha, coluna, &limpoCima);
        }
        if(limpoCima==1){
            colunaOpcao=varreEsquerdaDireita(posicoes, coluna, time);
            if(colunaOpcao>=0&&colunaOpcao<6){
                posicoes[colunaOpcao][coluna].opcao=1;
            }
            else if(colunaOpcao==6){
                direitaSuperior(posicoes, coluna, 0, index+1, time);
            }
        }
        if(limpoEsquerda==1){
            linhaOpcao=varreCimaBaixo(posicoes, linha, time);
            if(linhaOpcao>=0&&linhaOpcao<6){
                posicoes[linha][linhaOpcao].opcao=1;
            }
            else if(linhaOpcao==6){
                esquerdaInferior(posicoes, 0, linha, index+1, time);
            }
        }
    }
}
void direitaInferior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time){
    int limpoDireita=0, limpoBaixo=0;
    int colunaOpcao, linhaOpcao;

    if(index<4){
        if(linha==3||linha==4){
            verificaCaminhoDireita(posicoes, linha, coluna, &limpoDireita);
        }
        if(coluna==3||coluna==4){
            verificaCaminhoBaixo(posicoes, linha, coluna, &limpoBaixo);
        }
        if(limpoBaixo==1){
            colunaOpcao=varreDireitaEsquerda(posicoes, coluna, time);
            if(colunaOpcao>=0&&colunaOpcao<6){
                posicoes[colunaOpcao][coluna].opcao=1;
            }
            else if(colunaOpcao==6){
                esquerdaInferior(posicoes, coluna, 0, index+1, time);
            }
        }
        if(limpoDireita==1){
            linhaOpcao=varreBaixoCima(posicoes, linha, time);
            if(linhaOpcao>=0&&linhaOpcao<6){
                posicoes[linha][linhaOpcao].opcao=1;
            }
            else if(linhaOpcao==6){
                direitaSuperior(posicoes, 0, linha, index+1, time);
            }
        }
    }
}
void esquerdaInferior(struct Posicao posicoes[6][6], int linha, int coluna, int index, int time){
    int limpoEsquerda=0, limpoBaixo=0;
    int colunaOpcao, linhaOpcao;

    if(index<4){
        if(linha==3||linha==4){
            verificaCaminhoEsquerda(posicoes, linha, coluna, &limpoEsquerda);
        }
        if(coluna==1||coluna==2){
            verificaCaminhoBaixo(posicoes, linha, coluna, &limpoBaixo);
        }
        if(limpoBaixo==1){
            colunaOpcao=varreEsquerdaDireita(posicoes, 5-coluna, time);
            if(colunaOpcao>=0&&colunaOpcao<6){
                posicoes[colunaOpcao][5-coluna].opcao=1;
            }
            else if(colunaOpcao==6){
                direitaInferior(posicoes, 5-coluna, 0, index+1, time);
            }
        }
        if(limpoEsquerda==1){
            linhaOpcao=varreBaixoCima(posicoes, 5-linha, time);
            if(linhaOpcao>=0&&linhaOpcao<6){
                posicoes[5-linha][linhaOpcao].opcao=1;
            }
            else if(linhaOpcao==6){
                esquerdaSuperior(posicoes, 0, 5-linha, index+1, time);
            }
        }
    }

    
}