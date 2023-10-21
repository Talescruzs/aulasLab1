#include <stdio.h>

void string_circular(char str[], char dir, int n){
    int i, j=0, flag=0, count=0;
    char copiStr[30];

    for(i=0; str[i]!='\0';i++){
        copiStr[i] = str[i];
        count++;
    }
    while(n>=count){
        n-=count;
    }

    for(i=0; copiStr[i]!='\0';i++){
        if(dir=='e'){
            if(copiStr[i+n]=='\0'){
                flag=1;
            }
            if(flag==0){
                str[i] = copiStr[i+n];
            }
            else{
                str[i] = copiStr[j];
                j++;
            }
        }
        else{
            if(i-n>=0){
                flag=1;
            }
            if(flag==0){
                str[i] = copiStr[count-i-1];
                count--;
            }
            else{
                str[i] = copiStr[i-n];
            }
        }
    }
}

int main(){
    char continua='s', dir, str[30];
    int n;
    while(continua!='n'){
        if(continua!='s' && continua!='n'){
            printf("Opção invalida\n");
        }
        else{
            printf("> String: ");
            scanf("%s", str);
            do{
                printf("> Direção ('d' ou 'e'): ");
                scanf(" %c", &dir);
                if(dir!='d'&&dir!='e'){
                    printf("Opcao invalida, insira novamente a direcao\n");
                }
            }while(dir!='d'&&dir!='e');
            do{
                printf("> Deslocamentos (> 0): ");
                scanf("%d", &n);
                if(n<=0){
                    printf("Opcao invalida, o deslocamento deve ser maior que zero\n");
                }
            }while(n<=0);
            string_circular(str, dir, n);
            printf("< String final: %s\n", str);
        }
        printf("> Continuar ('s' ou 'n') ? ");
        scanf(" %c", &continua);
    }
    printf("* fim *\n");
    return 0;
}