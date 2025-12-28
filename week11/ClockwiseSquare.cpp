#include<iostream>
#include<iomanip>


void ClockwiseSquare(int arr[],int n){
    int results[20][20]={0};
    int rounds=0;


    if(n%2==1){
        rounds=n/2;
        int temp=0;
        for(int i=0; i<rounds; i++){
            
            for(int j=0; j<2*(rounds-i); j++){
                //向下
                results[j+i][n-1-i]=arr[j+temp];
                //向左
                results[n-i-1][n-1-i-j]=arr[j+2*(rounds-i)+temp];
                //向上
                results[n-1-i-j][i]=arr[j+4*(rounds-i)+temp];
                //向右
                results[i][j+i]=arr[j+6*(rounds-i)+temp];
            }
            temp+=4*2*(rounds-i);
        }
    results[n/2][n/2] = arr[n*n - 1];
    }
    else{
        rounds=n/2;
        int temp=0;
        for(int i=0; i<rounds; i++){
            
            for(int j=0; j<2*(rounds-i)-1; j++){
                //向下
                results[j+i][n-1-i]=arr[j+temp];
                //向左
                results[n-i-1][n-1-i-j]=arr[j+2*(rounds-i)-1+temp];
                //向上
                results[n-1-i-j][i]=arr[j+2*(2*(rounds-i)-1)+temp];
                //向右
                results[i][j+i]=arr[j+3*(2*(rounds-i)-1)+temp];
            }
            temp+=4*(2*(rounds-i)-1);
        }
    }



    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout<<std::setw(4)<<results[i][j];
        }
        std::cout<<std::endl;
    }
}

int main(){
    // int square[20][20];
    int n=7;
    // std::cin>>n;
    int number[400];
    for(int i=1; i<=n*n; i++){
        number[i-1]=i;
    }
    // int director=1;
    //1=下，2=上，3=左，4=右
    // int count=0;
    // int i=1

    ClockwiseSquare(number,n);
    return 0;
}