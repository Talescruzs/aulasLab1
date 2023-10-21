#ifndef __PERSONAGEM_H_
#define __PERSONAGEM_H_

struct Peca{
    int posX, posY;
    int time;
    int selecionada;
};

int selecionaPeca(int posx, int posy, struct Peca pecas[], int npecas);

#endif