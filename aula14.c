#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void exercicio1(){
    const int TAM = 10;
    int matriz[TAM][TAM], i, j;
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("Isira numero da posição %dx%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            if(j+i!=TAM-1)
                printf("%d  ", matriz[i][j]);
            else
                printf("    ");
        }
        printf("\n");
    }
}
void exercicio2(){
    const int TAM = 5;
    int matriz[TAM][TAM], matriz2[TAM][TAM], i, j;
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("Isira numero da posição %dx%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            if((i+j)%2==0)
                matriz2[i][j] = matriz[i][j];
            else
                matriz2[i][j]=0;
        }
    }
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("%d  ", matriz2[i][j]);
        }
        printf("\n");
    }
}
void exercicio3(){
    const int COL = 3;
    const int LIN = 2;
    int matriz[LIN][COL], i, j;
    for (i = 0; i < LIN; i++){
        for (j = 0; j < COL; j++){
            printf("Isira numero da posição %dx%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < COL; i++){
        for (j = 0; j < LIN; j++){
            printf("%d  ", matriz[j][i]);
        }
        printf("\n");
    }
}
void exercicio4(){
    const int TAM = 2;
    int matriz[TAM][TAM], i, j, DP=1, DS=1, D;
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("Isira numero da posição %dx%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            if(i==j)
                DP*=matriz[i][j];
            else if(j+i==TAM-1)
                DS*=matriz[i][j];
        }
    }
    D=DP-DS;
    printf("Determinante = %d\n", D);
}
void exercicio5(){
    const int TAM = 5;
    int matriz[TAM][TAM], matriz2[TAM][TAM], i, j;
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("Isira numero da posição %dx%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            matriz2[i][j]=matriz[i][j];
            if(i==2)
            matriz2[i][j]=matriz[5][j];
            if(j==3)
            matriz2[i][j]=matriz[i][5];
        }
    }
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            printf("%d  ", matriz2[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // exercicio1();
    // exercicio2();
    // exercicio3();
    // exercicio4();
    exercicio5();
    // exercicio6();
    // exercicio7();
    // exercicio8();
    // exercicio9();
    // exercicio10();

}
