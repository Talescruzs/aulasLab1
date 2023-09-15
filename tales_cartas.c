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
    printf("%d\n", minhaCarta);
    printf("%d\n", fora);
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
    int a; 
    a = partida(1);
    if(a==2){
        printf("ganhou\n");
    }
    else{
        printf("perdeu\n");
    }

    return 0;
}
