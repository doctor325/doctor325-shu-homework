#include<stdio.h>

int main(){
    int num;
    char sign;
    int arr[1000];
    int i;
    scanf("%d %c", &num, &sign);

    if(num>1000||num<1){
        return 1;
    }

    if(num==1){
        printf("%c",sign);
    }

    if(num>1){
    for(i=2;i<=num;i +=4){
        if(i=2){
            arr[i-2]=i/2;
        }
        else{
            arr[(i-6)/4] = i/2;
        }
        
    }
    while(){
            printf("%c",sign);
            for(int j=0;j<arr[i];j++){
                printf(" ");
            }
            printf("%c",sign);
            printf("\n");
        }
    }
    return 0;
}