#include<stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a,b,c;

    if(n<100||m>999){
        printf("error");
    }
    else if(n>m){
        return 1;
    }
    else{
        for(n;n<=m;n++){
            a=n/100;
            b=(n/10)%10;
            c=n%10;
            if(a*a*a+b*b*b+c*c*c==n){
                printf("%d ",n);
            }

        }
    }
    return 0;
}