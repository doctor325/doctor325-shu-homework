#include<iostream>

int main(){
    int n,k,x;
    std::cin>>n>>k>>x;
    int arr[200][200];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>arr[i][j];
        }
    }
    for(int j=1;j<=n;j+=2){
        int temp=((j+1)/2)%k;
        if(temp==0){
            for(int m=n-1;m>=0;m--){
                arr[m+k][j]=arr[m][j];
            }
            for(int m=0;m<k;m++){
                arr[m][j]=x;
            }
        }
        else{
            for(int m=n-1;m>=0;m--){
                arr[m+temp][j]=arr[m][j];
            }
            for(int m=0;m<temp;m++){
                arr[m][j]=x;
            }
        }
    }
    // std::cout<<std::endl;
    for(int i=0;i<n;i++){
        int result=0;
        for(int j=0;j<n;j++){
            result+=arr[i][j];
            // std::cout<<arr[i][j]<<" ";
        }
        // std::cout<<std::endl;
        std::cout<<result;
        if(i<n-1) std::cout<<" ";
    }
    return 0;
}