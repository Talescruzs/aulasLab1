#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void exercicio1(){
    int n, soma=0;
    do
    {
        printf("Insira numero: ");
        scanf("%d", &n);
        if(n>0){
            soma+=n;
        }
    } while (n>=0);
    printf("Soma = %d\n", soma);
}
void exercicio2(){
    int n, produto=1, cont=0;
    do
    {
        printf("Insira numero: ");
        scanf("%d", &n);
        if(n>0){
            produto*=n;
            cont++;
        }
    } while (n>0);
    printf("Produto = %d\n", produto);
    printf("Quantidade de numeros = %d\n", cont);
}
void exercicio3(){
    int mdc=1, n1, n2;
    printf("Insira n1: ");
    scanf("%d", &n1);
    printf("Insira n2: ");
    scanf("%d", &n2);
    do{
        mdc++;
    }while(!(n1%mdc==0&&n2%mdc==0)&&mdc<=n1&&mdc<=n2);
    if(mdc<=n1&&mdc<=n2)
        printf("MDC = %d\n", mdc);
    else
        printf("Não tem MDC\n");
}
void exercicio4(){
    srand(time(NULL));
    int a, b, c;
    do{
        a=(rand()%10);
        do{
            printf("Advinha o numero: ");
            scanf("%d", &b);
            if(a!=b)
                printf("Errou, seu lixo\n");
        }while (a!=b);
        printf("Acertouuu\n");
        printf("Quer continuar, noia??(1 para sim) ");
        scanf("%d", &c);
    }while(c==1);
}
void exercicio5(){
    int a, n=1;
    printf("Insira um numero: ");
    scanf("%d", &a);
    do{
        n++;
    } while ((n*n)<=a);
    printf("Foi este numero que vc pediu? %d\n", n);
}
void exercicio6v1(){
    int n, soma=0, cont=0;
    float media;
    do{
        printf("Insira numero, seu noia: ");
        scanf("%d", &n);
        if(n%2==0&&n>0){
            soma+=n;
            cont++;
        }
    }while(n!=0);
    media = (float)(soma/cont);
    printf("Media = %f", media);
}
void exercicio6v2(){
    int n=1, soma=0, cont=0;
    float media;
    while (n!=0){
        printf("Insira numero, seu noia: ");
        scanf("%d", &n);
        if(n%2==0&&n>0){
            soma+=n;
            cont++;
        }
    }
    media = (float)(soma/cont);
    printf("Media = %f", media);
}
int main()
{
    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    // exercicio5();
    // exercicio6v1();
    // exercicio6v2();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();

}
