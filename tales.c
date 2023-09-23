#include <stdio.h>

int pegaDigito(int numero, int posicao){
    int i, resto=1;
    for(i=1; i<posicao; i++){
        resto*=10;
    }
    numero-=numero%resto;
    numero/=resto;

    return numero%10;
}

int main(){
    int matricula, soma=0, i, DV, op=0;

    printf("Matricula: ");
    scanf("%d", &matricula);
    for(i=5; i>=1; i--){
        soma+=pegaDigito(matricula, i)*(4+i);
    }
    soma*=10;
    DV = soma%11;
    if(DV>9){
        DV=pegaDigito(DV, 1);
    }
    int  cont=0, contPassou, contRodou, contAproveitou;
    float nota=0, cargoHoraria=0, totalNota=0, totalHora=0, notaPassou=0, notaRodou=0, notaAproveitou=0;

    printf(" Insira os valores:\n");
    while(nota>=0&&cargoHoraria>=0){
        printf("Nota: ");
        scanf("%f", &nota);
        printf("Carga horária: ");
        scanf("%f", &cargoHoraria);
        if(nota>=7&&nota<=10){
            printf("Passou\n");
            cont++;
            contPassou++;
            totalNota+=nota;
            notaPassou+=nota;
            totalHora+=cargoHoraria;
        }
        else if(nota>10){
            printf("Valor inválido inserido\n");
        }
        else if(nota>=0&&nota<7){
            cont++;
            contRodou++;
            totalNota+=nota;
            notaRodou+=nota;
            totalHora+=cargoHoraria;
        }
    } 

    while(op!=5){
        printf("Opções de calculo do aluno %d-%d:\n", matricula, DV);
        printf("1- Média Geral Acumulada (MGA)\n");
        printf("2- Índice de desempenho Acadêmico (IDA)\n");
        printf("3- Média Total de Disciplinas (MTD)\n");
        printf("4- Percentual de Aproveitamento do Aluno (PAA)\n");
        printf("5- Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf(" Média Geral Acumulada (MGA):\n");
                printf("MGA = %f\n", notaPassou/contPassou);
                break;
            case 2:
                printf("1- Média Geral Acumulada (MGA)\n");
                break;
            case 3:
                printf("1- Média Geral Acumulada (MGA)\n");
                break;
            case 4:
                printf("1- Média Geral Acumulada (MGA)\n");
                break;
            default:
                printf("Opção inválida");
        }

    }
    
    

    return 0;
}