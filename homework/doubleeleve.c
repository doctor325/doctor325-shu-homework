#include<stdio.h>

double FinalPrice(double n);
    
int main(){
    double num1,num2,num3;
    printf("请输入三个实数:");
    scanf("%lf %lf %lf",&num1,&num2,&num3);
    
    double price1=FinalPrice(num1);
    double price2=FinalPrice(num2);
    double price3=FinalPrice(num3);
    
    double sum=price1+price2+price3;
    printf("一共花了%.2lf",sum);
    return 0;
}


double FinalPrice(double n){
    if(n>0&&n<9.9){
        n +=0.99;
    }
    return n;
}