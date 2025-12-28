#include<iostream>

int main(){
    int arr[5][5];
    for(int i=0 ;i<5; i++){
        for(int j=0; j<5;j++){
            std::cin>>arr[i][j];
        }
    }
    int result=0;
    for(int i=1 ;i<4; i++){
        for(int j=1; j<4;j++){
            result+=arr[i][j];
        }
    }
    std::cout<<result<<std::endl;
    return 0;
}