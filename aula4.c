#include <stdio.h>

void exercicio1(){
    float ms;
    printf("Escreva um valor em m/s: ");
    scanf("%f", &ms);
    printf("Em km/h = %.2f\n\n", ms*3.6);
}

void exercicio2(){
    int a,b,c;
    float d;
    a=5;
    b=2;
    c=a/b;
    printf("%d\n", c);
    d=(float)a/b;
    printf("%f\n\n", d);
}

void exercicio3(){
    float b,h;
    printf("digite a altura e a base: ");
    scanf("%f %f", &b, &h);
    printf("A area do triangulo = %f", (b*h)/2);
}

void exercicio4(){
    float valorHora, horas, salBruto, salLiquido;
    printf("Insira a hora de trabalho: ");
    scanf("%f", &valorHora);
    printf("Insira a quantidade de horas trabalhadas no mes: ");
    scanf("%f", &horas);
    salBruto = valorHora*horas;
    salLiquido = salBruto;
    salLiquido-=(salBruto*0.11)+(salBruto*0.08)+(salBruto*0.05);
    printf("Salario bruto = %.2f\n", salBruto);
    printf("Salario liquido = %.2f\n\n", salLiquido);
}

void exercicio5(){
    int a,b,c;
    printf("insira a e b: ");
    scanf("%d %d", &a, &b);
    printf("a = %d\nb = %d\n", a, b);
    c=a;
    a=b;
    b=c;
    printf("depois da troca:\n");
    printf("a = %d\nb = %d\n\n", a, b);
}

void exercicio6(){
    int a,b;
    printf("insira a e b: ");
    scanf("%d %d", &a, &b);
    printf("a = %d\nb = %d\n", a, b);
    a+=b;
    b=a-b;
    a=a-b;
    printf("depois da troca:\n");
    printf("a = %d\nb = %d\n\n", a, b);
}

void exercicio7(){
    float m1Terreno,m2Terreno,m1Casa,m2Casa;
    printf("Digite as dimensoes do terreno: ");
    scanf("%f %f", &m1Terreno, &m2Terreno);
    printf("Digite as dimensoes da casa: ");
    scanf("%f %f", &m1Casa, &m2Casa);
    printf("Total disponivel = %f metros quadrados", (m1Terreno*m2Terreno)-(m1Casa*m2Casa));
}

void exercicio8(){
    float odometroInicio, odometroFim, ganho, litroGastos;
    printf("Insira a marcação do odometro inicial: ");
    scanf("%f", &odometroInicio);
    printf("Insira a marcação do odometro final: ");
    scanf("%f", &odometroFim);
    printf("Insira a quantidade de gasolina gasta: ");
    scanf("%f", &litroGastos);
    printf("Insira o valor ganho: ");
    scanf("%f", &ganho);
    printf("Gasto km/l = %f\n", (odometroFim-odometroInicio)/litroGastos);
    printf("Lucro = %f\n\n", ganho-((odometroFim-odometroInicio)*litroGastos*6.99));
}

void exercicio9(){
    int m1,m5,m10,m25,m50,m100;
    printf("Insira a quantidade de moedas de 1 centavo: ");
    scanf("%d", &m1);
    printf("Insira a quantidade de moedas de 5 centavos: ");
    scanf("%d", &m5);
    printf("Insira a quantidade de moedas de 10 centavos: ");
    scanf("%d", &m10);
    printf("Insira a quantidade de moedas de 25 centavos: ");
    scanf("%d", &m25);
    printf("Insira a quantidade de moedas de 50 centavos: ");
    scanf("%d", &m50);
    printf("Insira a quantidade de moedas de 1 real: ");
    scanf("%d", &m100);
    printf("Valor economizado = %.2f reais\n\n", (float)(m1+m5*5+m10*10+m25*25+m50*50+m100*100)/100);
}

void exercicio10(){
    int nCarros;
    float vDiaria;
    printf("Insira a quantidade de carros: ");
    scanf("%d", &nCarros);
    printf("Insira o valor da diaria: ");
    scanf("%f", &vDiaria);
    float faturamentoBaseAnual = (nCarros/3)*12*vDiaria*30;
    printf("Faturamento anual = %f\n", faturamentoBaseAnual);
    printf("Valor das multas = %f\n", (faturamentoBaseAnual/12)*0.1);
    printf("Quantidade de carros no proximo ano = %d", (int)(nCarros-(nCarros*0.05)-(nCarros/8)));
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
    return 0;
}
