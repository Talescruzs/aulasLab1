#include <stdio.h>

void exercicio1(){
    char palavra[30], c1, c2;
    printf("Insira palavra: ");
    scanf("%s", palavra);
    printf("Insira caractere 1: ");
    scanf(" %c", &c1);
    printf("Insira caractere 2: ");
    scanf(" %c", &c2);
    for(int i=0; palavra[i] != '\0'; i++){
        if(palavra[i]==c1){
            palavra[i]=c2;
        }
    }
    printf("nova palavra: %s\n\n", palavra);
}
void exercicio2(){
    char s[30], c;
    int v[30], j=0;
    
    
    printf("Insira palavra: ");
    scanf("%s", s);
    printf("Insira caractere: ");
    scanf(" %c", &c);
    for(int i=0; s[i] != '\0'; i++){
        if(s[i]==c){
            v[j]=i;
            j++;
        }
    }
    for(int i=0; i<j; i++){
        printf("%d  ", v[i]);
    }
}
void exercicio3(){
    char palavra[30];
    int tam=0, i, j, flag=0;
    printf("Insira palavra: ");
    scanf("%s", palavra);
    for(i=0; palavra[i] != '\0'; i++){
        tam++;
    }
    for(i=0, j=tam-1; i<tam; i++, j--){
        if(palavra[i]!=palavra[j]){
            flag=1;
        }
    }
    if(flag==0){
        printf("Palindorma\n\n");
    }
    else{
        printf("Não palindroma\n\n");
    }
}
void exercicio4(){
    const int tam = 3;
    char palavras[tam][30];
    int i, j, count=0, maior=0, v[tam];
    for (i = 0; i < tam; i++){
        printf("Insira palavra: ");
        scanf("%s", palavras[i]);
    }
    for (i = 0; i < tam; i++){
        for(j=0; palavras[i][j] != '\0'; j++){
            count++;
        }
        v[i]=count;
        if(v[maior]<count){
            maior = i;
        }
        count=0;
    }
    printf("Te liga no vetor de tamanho das palavras:\n");
    for(i=0; i<tam; i++){
        printf("%d\n", v[i]);
    }
    printf("maior palavra = %s", palavras[maior]);
}
void exercicio5(){
    char palavra[30], palavra2[30];
    int flag=0;
    printf("Insira palavra: ");
    scanf("%s", palavra);
    for(int i=0; i<30; i++){
        if(palavra[i]=='\0'){
            flag=1;
        }
        if(flag==1){
            palavra2[i]='*';
        }
        else{
            palavra2[i]=palavra[i];
        }
        if(i==29){
            palavra2[i]='\0';
        }
    }
    printf("%s\n\n", palavra2);
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
