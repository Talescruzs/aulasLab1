#include <stdio.h>
#include <limits.h>

void exercicio1(){
    int agua, custo = 0;
    printf("digite a agua: ");
    scanf("%d", &agua);

    custo+=7;
    printf("%d 1\n",custo);
    if(agua>10){
        if(agua<=30){
            custo+=(agua-10);
        }
        else{
            custo+=20;
        }
        printf("%d 2\n",custo);
    }
    if(agua>30){
        if(agua<=100){
            custo+=(agua-10);
        }
        else{
            custo+=140;
        }
        printf("%d 3\n",custo);
    }
    if(agua>100){
        custo+=(agua-100)*5;
        printf("%d 4\n",custo);
    }
    printf("Custo total = %d\n\n", custo);
}

void exercicio2(){
    float a,b,c,d;
    printf("digite a: ");
    scanf("%f", &a);
    printf("digite b: ");
    scanf("%f", &b);
    printf("digite c: ");
    scanf("%f", &c);
    printf("digite d: ");
    scanf("%f", &d);

    if(a==(b+c+d)&&d==(b+c)&&b==c){
        printf("equilibrado\n\n");
    }
    else{
        printf("desequilibrado\n\n");
    }
}

void exercicio3(){
    float a,b,c;
    printf("digite a: ");
    scanf("%f", &a);
    printf("digite b: ");
    scanf("%f", &b);
    printf("digite c: ");
    scanf("%f", &c);

    if(a>b&&a>c){
        printf("a campeao com %f pontos\n", a);
        if(b>c){
            printf("b vice-campeao com %f pontos\n", b);
        }
        else{
            printf("c vice-campeao com %f pontos\n", c);
        }
    }
    else if(b>a &&b>c){
        printf("b campeao com %f pontos\n", b);
        if(a>c){
            printf("a vice-campeao com %f pontos\n", a);
        }
        else{
            printf("c vice-campeao com %f pontos\n", c);
        }
    }
    else{
        printf("c campeao com %f pontos\n", c);
        if(b>a){
            printf("b vice-campeao com %f pontos\n", b);
        }
        else{
            printf("a vice-campeao com %f pontos\n", a);
        }
    }
}

void exercicio4(){
    float palcoal, pgasolina, distalcoal, distgasolina;
    printf("digite preço alcool: ");
    scanf("%f", &palcoal);
    printf("digite preco gasolina: ");
    scanf("%f", &pgasolina);
    printf("digite km/l com alcool: ");
    scanf("%f", &distalcoal);
    printf("digite km/l com gasolina: ");
    scanf("%f", &distgasolina);

    float aprovalcool, aprovgasolina;

    aprovalcool = distalcoal/palcoal;
    aprovgasolina = distgasolina/pgasolina;

    if(aprovalcool>aprovgasolina){
        printf("Vale mais a pena usar alcool, com %f km/real", aprovalcool);
    }
    else{
        printf("Vale mais a pena usar gasolina, com %f km/real", aprovgasolina);
    }
}

void exercicio5(){
    int n, a=INT_MAX;
    char c;
    printf("digite numero: ");
    scanf("%d", &n);
    printf("digite operacao: ");
    scanf(" %c", &c);
    
    if(c=='+'){
        printf("%d\n", (n+a));
        if(n>0){
            printf("Overflow\n\n");
        }
        else{
            printf("Ok\n\n");
        }
    }
    else if(c=='*'){
        printf("%d\n", (n*a));
        if(n>1){
            printf("Overflow\n\n");
        }
        else{
            printf("Ok\n\n");
        }
    }
    else{
        printf("engracado");
    }
}

void exercicio6(){
    int mes,dia,hora,minuto,segundo;
    printf("Insira mes dia hora minuto segundo");
    scanf("%d %d %d %d %d", &mes,&dia,&hora,&minuto,&segundo);

    if(mes>=1){
        dia+=(mes*30);
    }
    if(dia>=1){
        hora+=(dia*24);
    }
    if(hora>=1){
        minuto+=(hora*60);
    }
    if(minuto>=1){
        segundo+=(minuto*60);
    }

    int brat,mazel,salek,tak,blip;
    blip = segundo/3;
    tak = blip/40;
    blip-=tak*40;
    salek = tak/15;
    tak-=salek*15;
    mazel = salek/30;
    salek-=mazel*30;
    brat = mazel/8;
    mazel-=brat*8;

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
}
