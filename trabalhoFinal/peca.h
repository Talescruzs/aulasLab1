#ifndef __PERSONAGEM_H_
#define __PERSONAGEM_H_

struct Peca{
    int posX, posY;
    int time;
    int selecionada;
};

struct Posicao{
    int posX, posY, estado;
};

void selecionaPeca(int posx, int posy, struct Peca pecas[], int npecas);
void localizaPeca(struct Posicao posicoes[6][6], struct Peca pecas[], int npecas);

#endif