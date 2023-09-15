#include <stdio.h>

int main(){
    char op1;
    printf("*****************\n*     ZOXY      *\n*****************\n");
    printf("Menu inicial\n a. Validação de data\n b. Diferença de horários\n c. Conversão de temperatura\n d. Cálculo de material\n");
    printf("> Selecione uma opção:_");
    scanf(" %c", &op1);
    if(op1=='a'||op1=='A'){
        printf("\nA > Validação de data\n");
        int dia, mes, ano;
        printf("> Dia: ");
        scanf("%d", &dia);
        printf("> Mês: ");
        scanf("%d", &mes);
        printf("> Ano: ");
        scanf("%d", &ano);
        if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
            if(!(dia>=0&&dia<=31)){
                printf("Erro, dia invalido\n");
                return 0;
            }
        }
        else if(mes==4||mes==6||mes==9||mes==11){
            if(!(dia>=0&&dia<=30)){
                printf("Erro, dia invalido\n");
                return 0;
            }
        }
        else if(mes==2){
            if(!(dia<=28||(dia<=29&&(ano%400==0||(ano%4==0&&ano%100!=0))))){
                printf("Erro, dia invalido\n");
                return 0;
            }
        }
        int op2;
        printf(" 1. DD/MM/YYYY\n");
        printf(" 2. YYYY-MM-DD\n");
        printf(" 3. DD de [MÊS] de YYYY\n");
        printf("> Selecione uma opçaõ:_");
        scanf("%d", &op2);
        if(op2==1){
            if(mes>=10){
                printf("< %d/%d/%d\n", dia, mes, ano);
            }
            else{
                printf("< %d/0%d/%d\n", dia, mes, ano);
            }
        }
        else if(op2==2){
            if(mes>=10){
                printf("< %d-%d-%d\n", ano, mes, dia);
            }
            else{
                printf("< %d-0%d-%d\n", ano, mes, dia);
            }
        }
        else if(op2==3){
            if(mes == 1){
                printf("< %d de janeiro de %d\n", dia, ano);
            }
            else if(mes == 2){
                printf("< %d de fevereiro de %d\n", dia, ano);
            }
            else if(mes == 3){
                printf("< %d de março de %d\n", dia, ano);
            }
            else if(mes == 4){
                printf("< %d de abril de %d\n", dia, ano);
            }
            else if(mes == 5){
                printf("< %d de maio de %d\n", dia, ano);
            }
            else if(mes == 6){
                printf("< %d de junho de %d\n", dia, ano);
            }
            else if(mes == 7){
                printf("< %d de julho de %d\n", dia, ano);
            }
            else if(mes == 8){
                printf("< %d de agosto de %d\n", dia, ano);
            }
            else if(mes == 9){
                printf("< %d de setembro de %d\n", dia, ano);
            }
            else if(mes == 10){
                printf("< %d de outubro de %d\n", dia, ano);
            }
            else if(mes == 11){
                printf("< %d de novembro de %d\n", dia, ano);
            }
            else if(mes == 12){
                printf("< %d de dezembro de %d\n", dia, ano);
            }
        }
        else{
            printf("Erro, opção inválida\n");
            return 0;
        }
        printf("*fim*\n");
        return 0;
    }
    else if(op1=='b'||op1=='B'){
        int h1,h2,m1,m2;
        int hr, mr;
        int op2;
        printf("\nB > Diferença de horários\n");
        printf("> Hora h1: ");
        scanf("%d", &h1);
        printf("> Minuto m1: ");
        scanf("%d", &m1);
        printf("> Hora h2: ");
        scanf("%d", &h2);
        printf("> Minuto m2: ");
        scanf("%d", &m2);

        if(h1>=24||h2>=24){
            printf("Erro, hora inválida\n");
            return 0;
        }
        if(m1>=60||h2>=60){
            printf("Erro, minuto inválido\n");
            return 0;
        }

        if(h2<h1||(h2==h1&&m2<m1)){
            h2+=24;
        }
        mr = m2-m1;
        hr = h2-h1;
        if(mr<0){
            mr+=60;
            hr-=1;
        }

        printf(" 1. Padrão\n");
        printf(" 2. Minutos\n");
        printf(" 3. Segundos\n");
        printf(" 4. Milisegundos\n");
        printf("> Selecione uma opção:_");
        scanf("%d", &op2);
        if(op2==1){
            if(mr==0){
                printf("< Diferença: %d horas\n", hr);
            }
            else if(hr==0){
                printf("< Diferença: %d minutos\n", mr);
            }
            else{
                printf("< Diferença: %d horas e %d minutos\n", hr, mr);
            }
        }
        else if(op2==2){
            printf("< Diferença: %dm\n", mr+(hr*60));
        }
        else if(op2==3){
            printf("< Diferença: %ds\n", (mr*60)+(hr*60*60));
        }
        else if(op2==4){
            printf("< Diferença: %dms\n", ((mr*60)+(hr*60*60))*1000);
        }
        else{
            printf("Erro, opção inválida\n");
            return 0;
        }

        printf("*fim*\n");
        return 0;
    }
    else if(op1=='c'||op1=='C'){
        float temp;
        int op2;

        printf("\nC > Conversão de temperatura\n");
        printf("> Temperatura (ºC): ");
        scanf("%f", &temp);

        printf(" 1. Fahrenheit\n");
        printf(" 2. Kelvin\n");
        printf(" 3. Rankine\n");
        printf("> Selecione uma opção:_");
        scanf("%d", &op2);

        if(op2==1){
            printf("< %.1fºC <-> %.1fºF\n", temp, (temp*9/5)+32);
        }
        else if(op2==2){
            printf("< %.1fºC <-> %.2fK\n", temp, temp+273.15);
        }
        else if(op2==3){
            printf("< %.1fºC <-> %.2fºR\n", temp, (temp*9/5)+491.67);
        }
        else{
            printf("Erro, opção inválida\n");
            return 0;
        }
        printf("*fim*\n");
        return 0;


    }
    else if(op1=='d'||op1=='D'){
        float altura, comprimento;
        float tamTijolo;
        int qtdTijolo;
        int op2;

        printf("\nD > Cálculo de material\n");
        printf("> Altura (m): ");
        scanf("%f", &altura);
        printf("> Comprimento (m): ");
        scanf("%f", &comprimento);
        printf(" 1. 6 furos\n");
        printf(" 2. 8 furos\n");
        printf(" 3. 9 furos\n");
        printf("> Selecione uma opção:_");
        scanf("%d", &op2);

        if(op2==1){
            tamTijolo = 0.14*0.19;
            qtdTijolo = (altura*comprimento)/tamTijolo;
            if(qtdTijolo<(altura*comprimento)/tamTijolo){
                qtdTijolo++;
            }
            printf("< Tijolos necessários: %d unidades (R$ %.2f)\n", qtdTijolo, (float)(qtdTijolo*400)/1000);
        }
        else if(op2==2){
            tamTijolo = 0.19*0.19;
            qtdTijolo = (altura*comprimento)/tamTijolo;
            if(qtdTijolo<(altura*comprimento)/tamTijolo){
                qtdTijolo++;
            }
            printf("< Tijolos necessários: %d unidades (R$ %.2f)\n", qtdTijolo, (float)(qtdTijolo*780.50)/1000);
        }
        else if(op2==3){
            tamTijolo = 0.19*0.29;
            qtdTijolo = (altura*comprimento)/tamTijolo;
            if(qtdTijolo<(altura*comprimento)/tamTijolo){
                qtdTijolo++;
            }
            printf("< Tijolos necessários: %d unidades (R$ %.2f)\n", qtdTijolo, (float)(qtdTijolo*899.99)/1000);
        }
        else{
            printf("Erro, opção inválida\n");
            return 0;
        }
        printf("*fim*\n");
        return 0;
    }
    else{
        printf("Erro, opção inválida\n");
        return 0;
    }

    return 0;
}
