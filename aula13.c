#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void exercicio1(){
    const int tam = 10;
    int vet[tam], i, count=0, n;
    printf("Insira numeros:\n");
    for(i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }
    printf("Insira o numero pra ver a frequencia: ");
    scanf("%d", &n);
    for(i=0; i<tam; i++){
        if(vet[i]==n){
            count++;
        }
    }
    printf("Frequencia de %d = %d\n", n, count);
}
void exercicio2(){
    const int tam = 5;
    float vet[tam];
    int i;
    printf("Insira numeros: ");
    for(i=0; i<tam; i++){
        scanf("%f", &vet[i]);
    }
    for(i=0; i<tam; i++){
        printf("%f ", vet[i]);
    }
    printf("\n");
    for(i=0; i<tam; i++){
        if(vet[i]==0){
            vet[i] = -99;
        }
    }
    for(i=0; i<tam; i++){
        printf("%f ", vet[i]);
    }
}
void exercicio3(){
    const int tam = 5;
    float vet[tam];
    int i;
    printf("Insira numeros: ");
    for(i=0; i<tam; i++){
        scanf("%f", &vet[i]);
    }
    for(i=0; i<tam; i++){
        printf("%f ", vet[i]);
    }
    printf("\n");

    float menor = vet[0];
    int pos = 0;

    for(i=0; i<tam; i++){
        if(vet[i]<menor){
            menor=vet[i];
            pos = i;
        }
    }
    printf("Menor numero = %f, na posição %d", menor, pos);
}
void exercicio4(){
    const int tam = 10;
    int vet[tam];
    int i, par=0, impar=0;
    printf("Insira numeros: ");
    for(i=0; i<tam; i++){
        scanf("%d", &vet[i]);
        if(vet[i]%2==0)
        par++;
        else
        impar++;
    }

    int parVet[par], imparVet[impar];
    int j=0, k=0;

    for(i=0; i<tam; i++){
        if(vet[i]%2==0){
            parVet[j]=vet[i];
            j++;
        }
        else{
            imparVet[k]=vet[i];
            k++;
        }
    }
    printf("Par:\n");
    for(i=0; i<j; i++){
        printf("%d ", parVet[i]);
    }
    printf("\nImpar:\n");
    for(i=0; i<k; i++){
        printf("%d ", imparVet[i]);
    }
}
void exercicio5(){
    const int tam = 10;
    int vet1[tam], vet2[tam], i;
    printf("Insira numeros:\n");
    for(i=0; i<tam; i++){
        scanf("%d", &vet1[i]);
    }
    for(i=0; i<tam; i++){
        vet2[i]=vet1[tam-i-1];
    }
    for(i=0; i<tam; i++){
        vet1[i] = vet2[i];
    }
    printf("Invertido: \n");
    for(i=0; i<tam; i++){
        printf("%d ", vet1[i]);
    }
    printf("\n");
}
void exercicio6(){
    const int tam = 5;
    int a[tam], b[tam], c[tam*2], i, j;
    printf("Insira numeros (para a):\n");
    for(i=0; i<tam; i++){
        scanf("%d", &a[i]);
    }
    printf("Insira numeros (para b):\n");
    for(i=0; i<tam; i++){
        scanf("%d", &b[i]);
    }

    for(i=0; i<tam*2; i++){
        for(j=0; j<tam; j++){

        }
    }
    
}


int main()
{
    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    // exercicio5();
    exercicio6();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();

}
