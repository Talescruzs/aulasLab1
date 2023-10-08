#include <stdio.h>

int main(){
    int t=-1, i, j, k, count=0, flag=0;

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

    float v2[t];
    count=0;
    flag=0;
    printf("> Digite v2: ");
    for(i=0; i<t; i++){
        scanf("%f", &v2[i]);
        for(j=0; j<count; j++){
            if(v2[i]==v2[j]){
                i--;
                flag=1;
            }
        }
        if(flag==0){
            count++;
        }
        else{
            printf("> Digite outros valores para v2: ");
            flag=0;
        }
    }

    float n=-1;
    while(n<0){
        printf("> Digite n: ");
        scanf("%f", &n);
    }

    float v3[t*2];
    flag=0;
    j=0;
    int flag1=0, flag2=0;
    for(i=0; i<t*2; i++){
        if(i%2==0){
            if(flag1==0){
                v3[i]=v1[j*2];
                flag1=1;
            }
            else{
                v3[i]=v2[(j*2)+1];
                flag1=0;
            }
        }
        else{
            if(flag2==0){
                v3[i]=v2[j*2];
                flag2=1;
            }
            else{
                v3[i]=v1[(j*2)+1];
                flag2=0;
                j++;
            }

        }

    }

    float v4[t*2], somado[t*2];
    for(i=0, j=(t*2)-1; i<t*2; i++, j--){
        if((int)v3[j]%2==0){
            v4[i]=v3[j]+n;
            somado[i]=n;
        }
        else{
            v4[i]=v3[j]+(n*2);
            somado[i]=n*2;
        }
    }
    
    printf("<v1: |");
    for(i=0; i<t; i++){
        printf(" %f |", v1[i]);
    }
    printf("\n");
    printf("<v2: |");
    for(i=0; i<t; i++){
        printf(" %f |", v2[i]);
    }
    printf("\n");
    printf("<v3: |");
    for(i=0; i<t*2; i++){
        printf(" %f |", v3[i]);
    }
    printf("\n");
    printf("<v4: |");
    for(i=0; i<t*2; i++){
        printf(" %f |", v4[i]);
    }

    printf("\n");
    for(i=0; i<t*2; i++){
        printf(" %f |", somado[i]);
    }

    float v5[t], v6[t];
    flag1=0, flag2=0;
    for(i=0, j=t*2-1; i<t*2; i++, j--){
        if(j%2==0){
            if(flag1==0){
                v5[i]=v4[j];
                flag1=1;
            }
            else{
                v3[i]=v2[(j*2)+1];
                flag1=0;
            }
        }
        else{
            if(flag2==0){
                v3[i]=v2[j*2];
                flag2=1;
            }
            else{
                v3[i]=v1[(j*2)+1];
                flag2=0;
                j++;
            }

        }
    }

    return 0;
}