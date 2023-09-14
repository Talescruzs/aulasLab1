#include <stdio.h>
#include <math.h>

void exercicio1(){
    int numero=1, primo=0, a, flag=1;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    while (numero!=0){
        a=numero-1;
        while (a>1){
            if(numero%a==0){
                flag=0;
            }
            a--;
        }
        if(flag && numero!=1)
            primo++;

        printf("Digite um numero: ");
        scanf("%d", &numero);
    }
    printf("Quantidade de primos = %d\n", primo);
}
int soma(int n, int m){
    int soma=0;
    if(m>n){
        while (n<=m){
            soma+=n;
            n++;
        }
    }
    else if(n>m){
        while (n>=m){
            soma+=n;
            n--;
        }
    }
    else{
        soma = n;
    }
    return soma;
}
void exercicio2(){
    int m,n;
    while (1){
        printf("Insira m: ");
        scanf("%d", &m);
        printf("Insira n: ");
        scanf("%d", &n);
        printf("Soma = %d\n", soma(n,m));
    }
    
}
int triangular(int n){
    int a=1;
    while(1)
    {
        printf("%d\n", a);
        if(a*(a+1)*(a+2)==n){
            return 1;
        }
        else{
            if(a*(a+1)*(a+2)>n){
                return 0;
            }
        }
        a++;
    }
}
void exercicio3(){
    int n;
    while (1){
        printf("Insira um numero: ");
        scanf("%d", &n);
        if(triangular(n)){
            printf("É triangular\n");
        }
        else{
            printf("Não é triangular\n");
        }
    }
}
void exercicio4(){
    int j = 110, c = 150, cont = 0;
    while (j<c){
        j+=3;
        c+=2;
        cont++;
    }
    printf("Serão necessários %d anos\n", cont);
}
int quadradoPerfeito(int n){
    int a=1, soma=0;
    while (1){
        if(a%2!=0){
            soma+=a;
        }
        if(soma==n){
            return 1;
        }
        else if(soma>n){
            return 0;
        }
        a++;
    }
    
}
void exercicio5(){
    int n;
    while (1)
    {
        printf("Insira um numero: ");
        scanf("%d", &n);
        if(quadradoPerfeito(n)){
            printf("É quadrado perfeito\n");
        }
        else{
            printf("Não é quadrado perfeito\n");
        }
    }
    
}

int main()
{
    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    exercicio5();
    // exercicio6();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();

}
