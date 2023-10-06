#include <stdio.h>

int main(){
    int t=-1, i, j, count=0, flag=0;

    while(t<0){
        printf("> Digite t: ");
        scanf("%d", &t);
    }

    float v1[t];
    printf("> Digite v1: ");
    for(i=0; i<t; i++){
        scanf("%f", &v1[i]);
        for(j=0; j<count; j++){
            if(v1[i]==v1[j]){
                i--;
                flag=1;
            }
        }
        if(flag==0){
            count++;
        }
        else{
            printf("> Digite outros valores para v1: ");
            flag=0;
        }
    }

    for(i=0; i<t; i++){
        printf("%f ", v1[i]);
    }

    return 0;
}