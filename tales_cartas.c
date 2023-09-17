#include <stdio.h>
#include <time.h>

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

float simula(int nPartidas, int estrategia){
    float vitorias=0;
    int i, jogo;
    for(i=0;i<nPartidas;i++){
        jogo = partida(estrategia);
        if(jogo==2){
            vitorias++;
        }
    }
    return vitorias;
}

int main(){
    srand(time(NULL));
    float percentV1, percentV2, percentD, vitoria=0, derrota=0, total=1000000;
    
    vitoria = simula(total, 0);
    derrota=total-vitoria;

    percentV1=(vitoria/total)*100;
    percentD=(derrota/total)*100;

    printf("> Estratégia 1 (sem mudança de carta):\n");
    printf("    Partidas jogadas: 1000000\n");
    printf("    Partidas ganhas: %d\n", (int)vitoria);
    printf("    Partidas perdidas: %d\n", (int)derrota);
    printf("    %% de derrotas: %.2f%%\n", percentD);
    printf("    %% de vitorias: %.2f%%\n", percentV1);

    vitoria=0;
    derrota=0;

    vitoria = simula(total, 1);
    derrota=total-vitoria;

    percentV2=(vitoria/total)*100;
    percentD=(derrota/total)*100;

    printf("> Estratégia 2 (com mudança de carta):\n");
    printf("    Partidas jogadas: 1000000\n");
    printf("    Partidas ganhas: %d\n", (int)vitoria);
    printf("    Partidas perdidas: %d\n", (int)derrota);
    printf("    %% de derrotas: %.2f%%\n", percentD);
    printf("    %% de vitorias: %.2f%%\n", percentV2);

    if(percentV1>percentV2){
        printf("> Recomendação: Estratégia 1\n");
    }
    else if(percentV1<percentV2){
        printf("> Recomendação: Estratégia 2\n");
    }
    else{
        printf("> Recomendação: Indiferente\n");
    }
    return 0;
}