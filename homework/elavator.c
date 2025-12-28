#include<stdio.h>
#include<tgmath.h>

int main(){
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++){
    int A,B,N;
    scanf("%d %d %d",&N,&A,&B);

    int C,D;
    C = (fabs(N-A)+N-1)*5;
    D = (fabs(N-B)+N-1)*5;
    printf("%d %d\n",C,D);
    }
    return 0;

}