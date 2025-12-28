#include<stdio.h>
#include<math.h>

int main(){
    int n;
    int appleposition=0;
    int count=0;

    //scanf("%d",&n);
    n=5;

    while(n>0){
        count++;
        if(appleposition==0){
            if(n%3==1){
                appleposition=count;
            }
        }
        n = n-ceil(n/3.0);
 
    }
    printf("%d %d",count,appleposition);
    return 0;   
}