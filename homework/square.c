#include <stdio.h>
int C;long long int sum;
int main(){
    while(scanf("%d",&C)!=EOF){
        sum=C;
        if(C>1){
            sum+=C*(C-1)/2*(1+1+2);
        }
        if(C>2){
            sum+=3*C*(C-1)*(C-2)/2;
        }
        
        if(C>3){
            sum+=C*(C-1)*(C-2)*(C-3)/4;
        }
        if(C=3){
            sum-=3;
        }
        printf("%lld\n",sum);
    }
    return 0;
}