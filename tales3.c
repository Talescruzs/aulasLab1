#include <stdio.h>
#include <limits.h>

void ordena(int vet[], int tam){
    int i;
    for(i=0; i<tam; i++){
        for(int j=i; j<tam; j++){
            if (vet[i]>vet[j]){
                int temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

int mediana(int vet[], int tam){
    int med;
    if(tam%2==0){
        med = (int)(vet[(int)tam/2-1]+vet[((int)tam/2)])/2;
    }
    else{
        med = (int)(vet[(int)tam/2]);
    }
    return med;
}

int main(){
    int l=-1, c=-1, i, j;
    while(l<=0||l>100){
        printf("Insira as linhas: ");
        scanf("%d", &l);
    }
    while(c<=0||c>100){
        printf("Insira as colunas: ");
        scanf("%d", &c);
    }

    int m[l][c], med[l][c];
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            printf("Insira %dX%d: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    printf("\n");
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int x, y, count=0, teste;
    int vet[9];

    // scanf("%d %d", &x, &y);
    for(x=0; x<l; x++){
        for(y=0; y<c; y++){
            for(i=x-1; i<=x+1; i++){
                for(j=y-1; j<=y+1; j++){
                    if(i>=0 && j>=0 && i<l && j<c){
                        vet[count]=m[i][j];
                        count++;
                    }
                }
            }
            printf("Valores para mediana %dX%d:\n", x+1,y+1);
            for(i=0; i<count; i++){
                printf("%d ", vet[i]);
            }
            printf("\n");
            ordena(vet, count);
            printf("Valores para mediana ordenados %dX%d:\n", x+1,y+1);
            for(i=0; i<count; i++){
                printf("%d ", vet[i]);
            }
            printf("\n");
            med[x][y] = mediana(vet, count);
            printf("Mediana da vizinhança %dX%d = %d\n", x+1, y+1, med[x][y]);
            count=0;
        }
    }
    printf("\nMatriz:\n");
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            printf("%d ", med[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}