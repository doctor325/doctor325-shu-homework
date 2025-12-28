#include <stdio.h>
int C;
long long int sum;
int main(){
    while(scanf("%d",&C)!=EOF){
        if(C<=31&&C>0){
            sum=(C*C*C*C+C*C+2*C)/4;
            printf("%lld\n",sum);   
        }
    }
    return 0;
}