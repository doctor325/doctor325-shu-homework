#include<stdio.h>

int main(){
    int n=0;
    if(scanf("%d",&n)!=1){
        return 1;
    }
    
    if(n<=10||n>2147483647){
        return 0;
    }



    int arr[10];
    int m=n;
    int count = 0;
    int i;

    while(m > 0){
        arr[count++] = m% 10;
        m /= 10;
    }   
    
    if(arr[0]%2==0){
        if(count%2==0){
            for(i=count-1;i>-1;i-=2){
                printf("%d ",arr[i]);
            }

        }else{
            for(i=count-2;i>-1;i-=2){
                printf("%d ",arr[i]);
            }
        }

    }else{
        if(count%2!=0){
            for(i=count-1;i>-1;i-=2){
                printf("%d ",arr[i]);
            }
            
        }else{
            for(i=count-2;i>-1;i-=2){
                printf("%d ",arr[i]);
            }
        }
    }
    printf("\n");
    return 0;

}

