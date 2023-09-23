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
    int nota=0, cargoHoraria=0, cont=0, totalNota=0, totalHora=0;
    while(nota>=0&&cargoHoraria>=0){
        printf("Nota: ");
        scanf("%d", &nota);
        printf("Carga: ");
        scanf("%d", &nota);
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