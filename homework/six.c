#include<stdio.h>   
#include<math.h>

int main(){
    int T;
    scanf("%d",&T);

    for(int i=1;i<=T;i++)
    {   
        int n;
        scanf("%d",&n);

        int result2;
        for(int j=1;j<=n;j++)
        { 
            int result1 = n/j;
            result2 = result1 + result2;

        }
        if (result2%2 == 0){
            printf("0 \n");
        }
        else{
            printf("1 \n");
        }
    }

    return 0;
}




//int main(){
//  int T;
//scanf("%d",&T);

//for(int i=1; i<=T; i++) {
//        long long n;
//        scanf("%lld", &n);
//        
        // 计算 floor(sqrt(n)) 的奇偶性
//        long long sqrt_n = 0;
//        for(long long j=1; j*j<=n; j++) {
//            sqrt_n = j;
//        }
        
        // 输出奇偶性（0表示偶数，1表示奇数）
//        printf("%lld\n", sqrt_n % 2);
//    }

//    return 0;
//}