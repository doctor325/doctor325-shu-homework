#include<stdio.h>

int main(){
    int n=0,m=0;
    int count=0;
    scanf("%d %d",&n,&m);
    if(n<1900||m>2999){
        return 0;
    }
    while(n<=m){
        if(n%4==0&&n%100!=0||n%400==0){

           printf("%6d",n);
           count++;
           if(count % 5 == 0){
                printf("\n");
            }
        }
        if(n%4==0){
            n = n + 4;
        }
        else if(n%4==1){
            n=n+3;
        }
        else if(n%4==2){
            n=n+2;
        }
        else if(n%4==3){
            n=n+1;
        }
    

    }
     if(count % 5 != 0 && count > 0){
        printf("\n");
    }
    return 0;
}