#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void exercicio1(){
    const int tam = 100;
    int a[tam], i, count=0, j=0;
    printf("Insira numeros:\n");
    for(i=0; i<tam; i++){
        scanf("%d", &a[i]);
        if(a[i])
            count++;
    }
    int b[count];
    for(i=0; i<tam; i++){
        if(a[i]>0){
            b[j]=a[i];
            j++;
        }
    }
    for(i=0; i<j; i++){
        printf("%d ", b[i]);
    }
}
void exercicio2(){
    const int tam = 20;
    int a[tam], i;
    printf("Insira numeros:\n");
    for(i=0; i<tam; i++){
        scanf("%d", &a[i]);
    }
    for(i=tam-1; i>=0; i--){
        printf("%d ", a[i]);
    }
}
void exercicio3(){
    const int tam = 30;
    int a[tam], i, maior, menor;
    printf("Insira numeros:\n");
    for(i=0; i<tam; i++){
        scanf("%d", &a[i]);
    }
    maior = a[0];
    menor = a[0];
    for(i=0; i<tam; i++){
        if(a[i]>maior)
            maior = a[i];
        else if(a[i]<menor)
            menor = a[i];
    }
    printf("Diferença = %d", maior-menor);
}
void exercicio4(){
    const int tam = 10;
    int a[tam], i, qtdPar=0;
    printf("Insira numeros:\n");
    for(i=0; i<tam; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<tam; i++){
        if(a[i]%2==0)
            qtdPar++;
    }
    printf("Diferença = %d", qtdPar);
}
void exercicio5(){
    const int tam1 = 3;
    const int tam2 = 2;
    int a[tam1], b[tam2], i, j, z, count=0, flag=0;
    printf("Insira numeros matriz 1:\n");
    for(i=0; i<tam1; i++){
        scanf("%d", &a[i]);
    }
    printf("Insira numeros matriz 2:\n");
    for(i=0; i<tam2; i++){
        scanf("%d", &b[i]);
        for(j=0; j<tam1; j++){
            if(b[i]==a[j]&&flag==0){
                count++;
                flag=1;
            }
        }
        flag=0;
    }
    int c[count];
    for(z=0; z<count; z++){
        for(i=0; i<tam2; i++){
            for(j=0; j<tam1; j++){
                if(b[i]==a[j]&&flag==0){
                    c[z]=b[i];
                    flag=1;
                }
            }
        }
        flag=0;
    }
    for(z=0; z<count; z++){
        printf("%d ", c[z]);
    }
}
void teste(){
    int a, i;
    scanf("%d", &a);
    float b[a];
    for(i=0; i<a; i++){
        scanf("%f", &b[i]);
    }
    for(i=0; i<a; i++){
        printf("%f ", b[i]);
    }
}

int main()
{
    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    // exercicio5();
    // exercicio6();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();
    teste();

}
