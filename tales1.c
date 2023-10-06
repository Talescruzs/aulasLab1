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
float mediaSimples(int total, int qtd){
    return (float)total/qtd;
}

int main(){
    int matricula, soma=0, i, DV, op=0;

    printf("Insira a matrícula: ");
    scanf("%d", &matricula);
    matricula=matricula%100000;
    for(i=5; i>=1; i--){
        soma+=pegaDigito(matricula, i)*(4+i);
    }
    soma*=10;
    DV = soma%11;
    if(DV>9){
        DV=pegaDigito(DV, 1);
    }

    int contPassou=0, contRodou=0, contAproveitou=0, contRodouSemNota=0, ap;
    float nota=0, hora=0, notaMinima;
    float notaPassou=0, notaRodou=0, notaAproveitou=0;
    float horaPassou=0, horaRodou=0, horaAproveitou=0, presenca;
    float horaRodouSemNota=0;
    float MGA=0, MTD=0, IDA=0, PAA=0;
    float MDA=0, MDR;

    printf("Insira os valores solicitados:\n");
    printf(" Qual a nota minima para a aprovação nas disciplinas? ");
    scanf("%f", &notaMinima);
    while(nota>=0&&hora>=0){
        printf(" Nota tirada na disciplina: ");
        scanf("%f", &nota);
        if(nota>=0&&nota<=10){
            printf(" Carga horária da disciplina: ");
            scanf("%f", &hora);
            if(hora>0){
                printf(" Quantidade de horas presente na disciplina: ");
                scanf("%f", &presenca);
                if(presenca>=hora*0.75&&nota>=notaMinima){
                    printf(" Esta cadeira foi aproveitada ou dispensada? (1 para sim) ");
                    scanf("%d", &ap);
                }
            }
        }
        if(nota>=0){
            if(nota>10||hora<=0){
                printf("  Valor inválido inserido\n");
            }
            else if(presenca>=hora*0.75){
                if(nota>=notaMinima){
                    if(ap!=1){
                        contPassou++;
                        notaPassou+=nota;
                        horaPassou+=hora;
                    }
                    else{
                        contAproveitou++;
                        notaAproveitou+=nota;
                        horaAproveitou+=hora;
                    }
                    MDA+=nota*hora;
                }
                
                else{
                    contRodou++;
                    notaRodou+=nota;
                    horaRodou+=hora;
                    MDR+=nota*hora;
                }
            }
            else{
                contRodouSemNota++;
                horaRodouSemNota+=hora;
                MDR+=nota*hora;
            }
        }
    } 

    MTD=MDA-MDR;
    MGA=mediaSimples(notaPassou, contPassou);
    IDA+=mediaSimples(notaPassou, contPassou)*(horaPassou); // Média final das disciplinas aprovadas com nota * carga horária das disciplinas aprovadas com nota
    IDA+=mediaSimples(notaAproveitou, contAproveitou) * horaAproveitou; //  Média das médias das disciplinas aprovadas sem nota * carga horária das disciplinas aprovadas sem nota
    IDA-=(notaMinima-mediaSimples(notaAproveitou+notaPassou+notaRodou, contRodou+contPassou+contAproveitou+contRodouSemNota))*horaRodou; // difetenca da nota minima para a media final (todas as disciplinas)*carga horaria das disciplinas que rodou com nota
    IDA-=notaMinima*horaRodouSemNota;
    PAA=((contPassou+contAproveitou)*100)/(contRodou+contRodouSemNota+contPassou+contAproveitou);
    printf("%d\n", contPassou);
    printf("%d\n", contAproveitou);
    printf("%d\n", contRodou);
    printf("%d\n", contRodouSemNota);


    while(op!=5){
        printf("Opções de cálculo do aluno %d-%d:\n", matricula, DV);
        printf(" 1- Média Geral Acumulada (MGA)\n");
        printf(" 2- Índice de desempenho Acadêmico (IDA)\n");
        printf(" 3- Média Total de Disciplinas (MTD)\n");
        printf(" 4- Percentual de Aproveitamento do Aluno (PAA)\n");
        printf(" 5- Sair\n");
        printf(" Selecione a opção desejada para calcular: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("  Média Geral Acumulada (MGA):\n");
                printf("   MGA = %f\n", MGA);
                break;
            case 2:
                printf("  Índice de desempenho Acadêmico (IDA)\n");
                printf("   IDA = %f\n", IDA);
                break;
            case 3:
                printf("  Média Total de Disciplinas (MTD)\n");
                printf("   MTD = %f\n", MTD);
                break;
            case 4:
                printf("  Percentual de Aproveitamento do Aluno (PAA)\n");
                printf("   PAA = %f\n", PAA);
                if(PAA==100){
                    printf("   Parabéns ao aluno, passou em todas as disciplinas :)");
                }
                break;
            case 5:
                break;
            default:
                printf("  Opção inválida");
        }

    }
    
    

    return 0;
}