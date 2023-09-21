#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int primo(int n){
    int i;
    for (i = 2; i < n; i++){
        printf("%d\n", i);
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
void pares(int n){
    int p1=2, p2=2, t;
    while (p1<n&&p2<n){
        t=0;
        if(p1+p2==n){
            printf("%d + %d = %d\n", p1,p2,n);
            break;
        }
        if(p1>=p2){
            while (t==0){
                printf("A\n");
                p1++;
                t = primo(p1);
            }
        }
        else{
            while (t==0){
                printf("B\n");
                p2++;
                t = primo(p2);
            }
        }
        printf("p1 = %d\n", p1);
        printf("p2 = %d\n", p2);
    }
    
}

void exercicio1(){
    int n;
    while (1==1)
    {
        printf("Insere numero: ");
        scanf("%d", &n);
        if(n%2==0){
            pares(n);
        }
        else{
            printf("Nao e par\n");
        }
    }
}

void exercicio2(){
}

int tresdigitos(int n){
    n-=n%100;
    n/=100;
    if (n%2==0){
        return 0;
    }
    return 1;
    
}

void exercicio3(){
    int n=100;
    while (n>=100)
    {
        printf("Insira numero: ");
        scanf("%d", &n);
        if(n>=100){
            if(tresdigitos(n)==1){
                printf("Das centenas é impar\n");
            }
            else{
                printf("Das centenas é par\n");
            }
        }
    }
}

void divisores(int n){
    int i;
    for(i=1; i<=n; i++){
        if(n%i==0)
        printf("%d\n", i);
    }
}

void exercicio4(){
    int n, r=1;
    while (r==1){
        printf("Insira numero: ");
        scanf("%d", &n);
        printf("Divisores:\n");
        divisores(n);
        printf("Quer continuar? (1 para sim) ");
        scanf("%d", &r);
    }
}

void exercicio5(){
    int n=1, cont=1;

    while (n!=0){
        printf("Insira numero: ");
        scanf("%d", &n);
        if (n!=0){
            if (n%cont==0){
                printf("%d\n", n);
            }
        }
        cont++;
    }
}

int main()
{
    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    exercicio5();
    // exercicio6v1();
    // exercicio6v2();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();

}
