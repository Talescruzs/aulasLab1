#include <stdio.h>
#include <math.h>

void exercicio1(){
    int inicio, fim, soma=0, i;
    printf("Inicio: ");
    scanf("%d", &inicio);
    printf("Fim: ");
    scanf("%d", &fim);

    for(i=inicio;i<=fim; i++){
        if(i%2!=0){
            printf("%d impar\n", i);
            soma+=i;
        }
    }
    printf("soma = %d\n", soma);
}

void exercicio2(){
    int i, maior = 0, atual;
    for(i=0;i<20;i++){
        printf("Digite numero: ");
        scanf("%d", &atual);
        if(atual>maior){
            maior = atual;
        }
    }
    printf("Maior = %d", maior);
}

void exercicio3(){
    int i, matricula;
    float nota1,nota2,nota3, media=0;
    for(i=0; i<10; i++){
        printf("Matricula: ");
        scanf("%d", &matricula);
        printf("Nota 1: ");
        scanf("%f", &nota1);
        printf("Nota 2: ");
        scanf("%f", &nota2);
        printf("Nota 3: ");
        scanf("%f", &nota3);
            
        media=(nota1*4+nota2*3+nota3*3)/10;
        printf("Aluno %d notas %.2f, %.2f, %.2f, media %f ", matricula, nota1, nota2, nota3, media);
        if(media>=7)
            printf("APROVADO\n");
        else
            printf("REPROVADO\n");
    }
}

void exercicio4(){
    int n, i, cont=0;
    printf("Insira numero: ");
    scanf("%d", &n);
    if(n==1){
        printf("1 não é primo pela definição de que numero primo é aquele que possui exatamente 2 divisores inteiros");
    }
    else{
        for(i=n-1; i>1; i--){
            if(n%i==0 && cont==0){
                printf("Não é primo, lista de divisores:\n");
                printf("%d\n", n);
                cont++;
            }
            if(cont>0 && n%i==0){
                printf("%d\n", i);
            }
        }
        if(cont>0){
            printf("1\n");
        }
        else{
            printf("É primo");
        }
    }
}

void exercicio5(){
    int i, j;
    float s=0;
    for(i=1, j=1; i<100; i+=2, j++){
        s+=(float)i/j;
    }
    printf("%.2f\n", s);
}

void exercicio6(){
    int v, i, v1=0, v2=1, vf=0;
    printf("Insira o termo: ");
    scanf("%d", &v);
    if(v<=0){
        printf("Não existe");
    }
    else if(v==1){
        printf("0");
    }
    else if(v==2){
        printf("1");
    }
    else{
        for(i=3; i<=v; i++){
            vf=v1+v2;
            if(v1>v2){
                v2=vf;
            }
            else{
                v1=vf;
            }
        }
    }
    printf("%d\n", vf);
}

void exercicio7(){
    int tab, limite, i;
    printf("Insira o numero: ");
    scanf("%d", &tab);
    printf("Insira o limite: ");
    scanf("%d", &limite);
    for(i=1; i<=limite; i++){
        printf("%d * %d = %d\n", tab, i, tab*i);
    }
}

void exercicio8(){
    printf("cansei")
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
    exercicio8();
    // exercicio9();
    // exercicio10();

}
