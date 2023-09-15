#include <stdio.h>
#include <math.h>

void exercicio1(){
    int a,b;
    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &a, &b);
    if(a%b==0||b%a==0){
        printf("Sao multiplos\n\n");
    }
    else{
        printf("Nao sao multiplos\n\n");
    }
}
void exercicio2(){
    float v;
    printf("Digite um valor inteiro: ");
    scanf("%f", &v);
    if(v<0){
        printf("Negativo\n\n");
    }
    else if(v>0){
        printf("Positivo\n\n");
    }
    else{
        printf("Nulo\n\n");
    }
}
void exercicio3(){
    int v;
    printf("Digite um valor inteiro: ");
    scanf("%d", &v);
    if(v>0){
        printf("%f\n\n", (float)1/v);
    }
    else{
        printf("%d\n\n", (int)fabs(v));
    }
}
void exercicio4(){
    int v;
    printf("Digite um valor inteiro: ");
    scanf("%d", &v);
    if(v%3==0&&v%7==0){
        printf("Divisivel\n\n");
    }
    else{
        printf("Nao divisivel\n\n");
    }
}
void exercicio5(){
    float a,b,c,delta;
    printf("Insira os coeficientes:\n");
    printf("A = ");
    scanf("%f", &a);
    printf("B = ");
    scanf("%f", &b);
    printf("C = ");
    scanf("%f", &c);

    delta = (b*b)-(4*a*c);
    if(delta<0){
        printf("Nao tem raizes reais");
    }
    else if(a==0){
        printf("A unica raiz = %f", (-c)/b);
    }
    else{
        float x1, x2, d;
        d = sqrt(delta);
        x1 = (-b + d)/2*a;
        x2 = (-b - d)/2*a;
        printf("Uma raiz = %f\nOutra = %f\n\n", x1,x2);
    }
}
void exercicio6(){
    float altura;
    char sexo;
    printf("Insira seu sexo (M ou F): ");
    scanf("%c", &sexo);
    printf("Insira sua altura em centimetros: ");
    scanf("%f", &altura);
    if(sexo == 'm' || sexo=='M'){
        printf("O peso ideal = %f\n\n", (72.7*altura/100)-58);
    }
    else if(sexo == 'f' || sexo=='F'){
        printf("O peso ideal = %f\n\n", (62.1*altura/100)-44.7);
    }
    else{
        printf("verme");
    }
}
void exercicio7(){
    char operacao;
    float n1, n2;
    
    printf("Digite dois numeros: ");
    scanf("%f %f", &n1, &n2);

    printf("Digite a operacao (+, -, / ou *): ");
    scanf(" %c", &operacao);

    if(operacao=='+'){
        printf("Resultado = %f", n1+n2);
    }
    else if(operacao=='-'){
        printf("Resultado = %f", n1-n2);
    }
    else if(operacao=='*'){
        printf("Resultado = %f", n1*n2);
    }
    else if(operacao=='/'){
        if(n2!=0){
            printf("Resultado = %f", n1/n2);
        }
        else{
            printf("Tá de sacanegem dividindo por zero, zé");
        }
    }
}

void exercicio8(){
    //a fazer
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

    return 0;
}
