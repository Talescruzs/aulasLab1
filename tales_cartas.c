#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partida(int estrategia){
    int asEspadas=2, asBastos=1, seteEspadas=0, aleatorio, minhaCarta, fora, i;
    aleatorio = rand() % 3;
    minhaCarta=aleatorio;
    for(i=2; i>1; i++){
        aleatorio = rand() % 3;
        if(aleatorio!=minhaCarta && aleatorio!=asEspadas){
            i=0;
            fora = aleatorio;
        }
    }
    if(estrategia==1){
        if(minhaCarta==asEspadas){
            if(fora==asBastos){
                minhaCarta=seteEspadas;
            }
            else{
                minhaCarta=asBastos;
            }
        }
        else if(minhaCarta==asBastos){
            minhaCarta=asEspadas;
        }
        else{
            minhaCarta=asEspadas;
        }
    }
    return minhaCarta;
}

int main(){
    srand(time(NULL));
    int jogo, i; 
    float percentV, percentD, vitoria=0, derrota=0, total=1000000;
    for(i=0;i<total;i++){
        jogo = partida(0);
        if(jogo==2){
            vitoria++;
        }
        else{
            derrota++;
        }
    }
    percentV=(vitoria/total)*100;
    percentD=(derrota/total)*100;

    printf("> Estratégia 1 (sem mudança de carta):\n");
    printf("    Partidas jogadas: 1000000\n");
    printf("    Partidas ganhas: %d\n", (int)vitoria);
    printf("    Partidas perdidas: %d\n", (int)derrota);
    printf("    %% de derrotas: %.2f%%\n", percentD);
    printf("    %% de vitorias: %.2f%%\n", percentV);

    vitoria=0;

    for(i=0;i<total;i++){
        jogo = partida(1);
        if(jogo==2){
            vitoria++;
        }
        else{
            derrota++;
        }
    }
    percentV=(vitoria/total)*100;
    percentD=(derrota/total)*100;

    printf("> Estratégia 2 (com mudança de carta):\n");
    printf("    Partidas jogadas: 1000000\n");
    printf("    Partidas ganhas: %d\n", (int)vitoria);
    printf("    Partidas perdidas: %d\n", (int)derrota);
    printf("    %% de derrotas: %.2f%%\n", percentD);
    printf("    %% de vitorias: %.2f%%\n", percentV);

    return 0;
}
