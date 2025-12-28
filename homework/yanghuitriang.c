#include<stdio.h>

int factorial(int n);
int combination(int n, int k);
void Print(int lines);

int main(){
    int lines=6;

    Print(lines);
    return 0;
}

int factorial(int n){
    int result=0;
    if(n<=1){
        return 1;
    }
    result=n*factorial(n-1);
    return result;
}


int combination(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}
void Print(int lines){
    
    for(int i=0;i<lines;i++){
        for(int j=0;j<(lines-(i+1))*2;j++){
            printf(" ");
        }
        for(int k = 0; k <= i; k++){
            int result;
            if(k == 0 || k == i){
                result = 1;
            }
            else{
                result = combination(i, k);
            }
            printf("%4d",result);
        }
        printf("\n");
    }
}