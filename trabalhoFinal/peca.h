#ifndef __PECA_H_
#define __PECA_H_

struct Posicao{
    int posX, posY, estado, selecionada, opcao;
};

void selecionaPeca(int posx, int posy, struct Posicao posicoes[6][6], int*rodada);
void movePeca(int posx, int posy, struct Posicao posicoes[6][6], int*rodada);
void localizaPeca(struct Posicao posicoes[6][6]);

#endif