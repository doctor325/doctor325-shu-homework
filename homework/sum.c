#include<stdio.h>

int main(){
    int T=0;
    scanf("%d",&T);


    if(T%3!=0){
        return 0;
    }
     int arr[T];

    for(int i = 0; i < T; i++){
        scanf("%d", &arr[i]);
    }
    
    int sum = 0;  
    

    for(int i = 0; i < T; i += 3){
       
        int max = arr[i];
        if(arr[i+1] > max){
            max = arr[i+1];
        }
        if(arr[i+2] > max){
            max = arr[i+2];
        }
        
        sum += max;
    }
    printf("%d\n", sum);
    return 0;
}