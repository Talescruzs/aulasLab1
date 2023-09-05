#include <stdio.h>
#include <math.h>

void exercicio1(int final, int mes){
    final = final%10;
    if(final==mes){
        printf("Mes da pagar\n");
    }
    else{
        printf("Só paga no mes %d\n", mes);
    }

}

int exercicio2(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22){
    if((y11>=y21&&y11<=y22)||(y12>=y21&&y12<=y22)){
        if((x11>=x21&&x11<=x22)||(x12>=x21&&x12<=x22)){
            return 1;
        }
        return 0;
    }
    return 0;

}

float exercicio3(int entradaH, int entradaM, int saidaH, int saidaM){
    if(saidaH<entradaH||(saidaH==entradaH&&entradaM>=saidaM)){
        saidaH+=24;
    }
    int tempoH = saidaH-entradaH;
    int tempoM = saidaM-entradaM;
    float preco=0;
    // printf("%d\n", tempoH);
    int resto;
    if(tempoM>0){
        tempoH++;
    }
    if(tempoH>=5){
        resto = tempoH-4;
        preco+=resto*2;
        tempoH-=resto;
    }
    if(tempoH>=3){
        resto = tempoH-2;
        preco+=resto*1.4;
        tempoH-=resto;
    }
    if(tempoH>=1){
        resto = tempoH;
        preco+=resto*1;
        tempoH-=resto;
    }
    return preco;
}

int main()
{
    // exercicio1(1111, 1);

    // int a = exercicio2(0, 0, 1, 1, 2, 2, 3, 3);
    // printf("%d\n", a);

    float a = exercicio3(12, 0, 13, 30);
    printf("%f\n", a);
    // exercicio4();
    // exercicio5();
    // exercicio6();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();

}
