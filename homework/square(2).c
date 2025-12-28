//DHU CTQ版权所有，禁止抄袭！！！尤其是wjx童鞋
#include <stdio.h>
int C;long long int sum;
int main(){
    while(scanf("%d",&C)<32){
        sum=C;//棋盘只有一种颜色
        if(C>1){
            sum+=C*(C-1)/2*(1+1+2);
        }//棋盘有两种颜色
        if(C>2){
            sum+=3*C*(C-1)*(C-2)/2;
        }
        //棋盘有三种颜色
        if(C>3){
            sum+=C*(C-1)*(C-2)*(C-3)/4;
        }//棋盘有四种颜色
        printf("%lld\n",sum);
    }
    return 0;
}