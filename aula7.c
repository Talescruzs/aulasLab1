#include <stdio.h>

void exercicio1(){
    unsigned int i;
    float a = 1, b = 2, c = 3;
    printf("Escreva i: ");
    scanf("%d", &i);
    switch (i)
    {
    
    case 1:
        if(a<b&&a<c){
            if(b<c){
                printf("%f, %f, %f\n\n", a,b,c);
            }
            else{
                printf("%f, %f, %f\n\n", a,c,b);
            }
        }
        else if(b<a && b<c){
            if(a<c){
                printf("%f, %f, %f\n\n", b,a,c);
            }
            else{
                printf("%f, %f, %f\n\n", b,c,a);
            }
        }
        else{
            if(a<b){
                printf("%f, %f, %f\n\n", c,a,b);
            }
            else{
                printf("%f, %f, %f\n\n", c,b,a);
            }
        }
        break;

    case 2:
        if(a>b&&a>c){
            if(b>c){
                printf("%f, %f, %f\n\n", a,b,c);
            }
            else{
                printf("%f, %f, %f\n\n", a,c,b);
            }
        }
        else if(b>a && b>c){
            if(a>c){
                printf("%f, %f, %f\n\n", b,a,c);
            }
            else{
                printf("%f, %f, %f\n\n", b,c,a);
            }
        }
        else{
            if(a>b){
                printf("%f, %f, %f\n\n", c,a,b);
            }
            else{
                printf("%f, %f, %f\n\n", c,b,a);
            }
        }
        break;
    case 3:
        if(a>b&&a>c){
            printf("%f, %f, %f\n\n", b,a,c);
        }
        else if(b>a && b>c){
            printf("%f, %f, %f\n\n", a,b,c);
        }
        else{
            printf("%f, %f, %f\n\n", a,c,b);
        }
        break;
    
    default:
        printf("Invalido\n\n");
        break;
    }
}

void exercicio2(){
    float a,b;
    char op;
    printf("Insira os numeros: ");
    scanf("%f %f", &a,&b);
    printf("Insira a operação: ");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        printf("Resultado = %f\n\n", (a+b));
        break;
    case '-':
        printf("Resultado = %f\n\n", (a-b));
        break;
    case '*':
        printf("Resultado = %f\n\n", (a*b));
        break;
    case '/':
        if(b==0){
            printf("Invalido\n\n");
        }
        else{
            printf("Resultado = %f\n\n", (a/b));
        }
        break;
    default:
        printf("Invalido\n\n");
        break;
    }
}

void exercicio3(){
    int cod;
    printf("Insira o código: ");
    scanf("%d", &cod);
    switch (cod)
    {
    case 1:
        printf("Alimento não perecivel\n\n");
        break;
    case 2: case 3: case 4:
        printf("Alimento perecivel\n\n");
        break;
    case 5: case 6:
        printf("Higiene pessoal\n\n");
        break;
    case 7:
        printf("Utensílio doméstico\n\n");
        break;
    default:
        if(cod>7&&cod<=12){
            printf("Limpeza\n\n");
        }
        else{
            printf("Código invalido\n\n");
        }
        break;
    }
}

void exercicio4(){
    int x,y;
    char op;

    printf("Insira os numeros: ");
    scanf("%d %d", &x,&y);
    printf("Insira a operação: ");
    scanf(" %c", &op);

    switch (op)
    {
    case 'A':
        printf("Resultado = %f\n\n", (float)(x+y)/2);
        break;
    case 'P':
        printf("Resultado = %f\n\n", (float)(x*4+y*6)/10);
        break;
    case 'R':
        printf("Resultado = %f\n\n", (float)(y%x));
        break;
    default:
        printf("Invalido\n\n");
        break;
    }
}

void exercicio5(){
    float peso;
    int planeta;
    printf("Insira peso: ");
    scanf("%f", &peso);
    printf("Isira planeta: ");
    scanf("%d", &planeta);
    switch (planeta)
    {
    case 1:
        printf("Peso no planeta = %.2f", peso*0.37);
        break;
    case 2:
        printf("Peso no planeta = %.2f", peso*0.88);
        break;
    case 3:
        printf("Peso no planeta = %.2f", peso*0.38);
        break;
    case 4:
        printf("Peso no planeta = %.2f", peso*2.64);
        break;
    case 5:
        printf("Peso no planeta = %.2f", peso*1.15);
        break;
    case 6:
        printf("Peso no planeta = %.2f", peso*1.17);
        break;
    default:
        printf("Código inválido");
        break;
    }
}

void exercicio6(){
    int mes;
    printf("Insira dia: ");
    scanf("%d", &mes);
    switch (mes)
    {
    case 2:
        printf("28\n\n");
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        printf("31\n\n");
        break;
    case 4: case 6: case 9: case 11:
        printf("30\n\n");
        break;
    default:
        printf("Mes inválido\n\n");
        break;
    }
}

void exercicio7(){
    float altura;
    char sexo;
    printf("Insira altura(cm): ");
    scanf(" %f", &altura);
    printf("Insira sexo: ");
    scanf(" %c", &sexo);
    switch (sexo)
    {
    case 'M':
        printf("Peso ideal = %f\n\n", (altura-100)*0.9);
        break;
    case 'F':
        printf("Peso ideal = %f\n\n", (altura-100)*0.85);
        break;
    default:
        printf("Inválido\n\n");
        break;
    }
}

void exercicio8(){
    float salario;
    char plano;
    printf("Insira salario: ");
    scanf("%f", &salario);
    printf("Insira plano: ");
    scanf(" %c", &plano);

    switch (plano)
    {
    case 'A':
        printf("Novo salario = %f\n\n", salario*1.09);
        break;
    case 'B':
        printf("Novo salario = %f\n\n", salario*1.13);
        break;
    case 'C':
        printf("Novo salario = %f\n\n", salario*1.17);
        break;
    default:
        printf("Inválido\n\n");
        break;
    }
}

void exercicio9(){
    int x, y, z;
    printf("Insira x e y: ");
    scanf("%d %d", &x, &y);
    z = (x>y) ? x : y;
    printf("Z = %d\n\n", z);
}

void exercicio10(){
    int x;
    printf("Insira numero: ");
    scanf("%d", &x);
    printf((x%2==0) ? ("Par\n\n") : ("Impar\n\n"));
}

int main()
{
    exercicio1();
    exercicio2();
    exercicio3();
    exercicio4();
    exercicio5();
    exercicio6();
    exercicio7();
    exercicio8();
    exercicio9();
    exercicio10();

}
