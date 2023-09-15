#include <stdio.h>

void exercicio1(){
    float n1, n2;
    int p1, p2;
    printf("Nota um:");
    scanf("%f", &n1);
    printf("peso um:");
    scanf("%d", &p1);
    printf("Nota dois:");
    scanf("%f", &n2);
    printf("peso dois:");
    scanf("%d", &p2);
    
    printf("Média final = %f\n\n", ((n1*p1)+n2*p2)/(p1+p2));
}

void exercicio2(){
    int x, y;
    printf("Insira x:");
    scanf("%d", &x);
    printf("Insira y:");
    scanf("%d", &y);
    printf("antecessor de y = %d\n", --y);
    printf("sucessor de x = %d\n\n", ++x);
}

void exercicio3(){
    float temp;
    printf("Insira temp em celsius: ");
    scanf("%f", &temp);
    printf("Temperatura em fahrenheit = %f\n\n", (1.8*temp)+32);
}

void exercicio4(){
    float preco;
    printf("Insira o preco do produto: ");
    scanf("%f", &preco);
    float desconto = preco*0.1;
    printf("O preco base = %f\nO novo preco = %f\n", preco, (preco-desconto));
    preco += preco*0.2;
    desconto = preco*0.1;
    printf("O preco base = %f\nO novo preco = %f\n\n", preco, (preco-desconto));
}

void exercicio5(){
    int idade;
    printf("Digite idade: ");
    scanf("%d", &idade);
    printf("Em dias = %d\n\n", idade*356);
}

void exercicio6(){
    int num, i;
    printf("Digite um numero de 3 digitos: ");
    scanf("%d", &num);

    num-=num%10;
    num/=10;
    num=num%10;

    printf("o digito das dezenas = %d\n\n", num);
}

void exercicio7(){
    int data;
    printf("Digita data ddmmaaaa: ");
    scanf("%d", &data);
    int ano = data%10000;
    data-=ano;
    data/=10000;
    int mes = data%100;
    data-=mes;
    data/=100;
    int dia = data;
    printf("dia = %d\nmes = %d\nano = %d\n\n", dia, mes, ano);
}

void exercicio8(){
    float razao, termo;
    printf("Digite a razao: ");
    scanf("%f", &razao);
    printf("Digite o primeiro termo: ");
    scanf("%f", &termo);
    printf("O decimo termo = %f", (razao*9)+termo);
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

    return 0;
}
