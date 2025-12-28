#include<stdio.h>

int main(){
    int n=0;
    scanf("%d",&n);
    printf("%d=",n);

    if(n<2){
        return 0;
    }


    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            printf("%d",i);
            n/=i;
            if(n!=1) printf("*");
        }
        
        }
        if(n>1){
            printf("%d",n);
    }
    return 0;

}




#include<stdio.h>

int main(){
    long long n = 0;  // 使用long long支持更大的数
    scanf("%lld", &n);
    printf("%lld=", n);

    if(n < 2){
        return 0;
    }

    int first = 1;  // 标记是否是第一个因子
    
    // 处理因子2
    while(n % 2 == 0){
        if(!first){
            printf("*");
        }
        printf("2");
        n /= 2;
        first = 0;
    }
    
    // 处理奇数因子，只需检查到sqrt(n)
    for(long long i = 3; i * i <= n; i += 2){
        while(n % i == 0){
            if(!first){
                printf("*");
            }
            printf("%lld", i);
            n /= i;
            first = 0;
        }
    }
    
    // 如果n仍大于1，则n本身是一个质因子
    if(n > 1){
        if(!first){
            printf("*");
        }
        printf("%lld", n);
    }
    
    printf("\n");
    return 0;
}