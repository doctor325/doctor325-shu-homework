#include<iostream>

int Akm(int m, int n){
    if(m==0) return n+1;
    else if(m>0&&n==0) return Akm(m-1,1);
    else if(m>0&&n>0) return Akm(m-1,Akm(m,n-1));
    return -1; // This line should never be reached for valid inputs
}

int main(){
    int m,n;
    std::cin>>m>>n;
    int result = Akm(m,n);
    std::cout<<result<<std::endl;
    return 0;
}