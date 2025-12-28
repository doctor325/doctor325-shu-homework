#include<iostream>

int main(){
    int T;
    std::cin>>T;
    while(T--){
        int m,n;
        std::cin>>m>>n;
        int arr[100][100];
        bool is_saddle=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                std::cin>>arr[i][j];
            }
        }
        for(int i=0;i<m;i++){
            int min=arr[i][0];
            int max=0;
            for(int j=0;j<n;j++){
                if(min>arr[i][j]){
                    min=arr[i][j];
                }
            }
            for(int j=0;j<n;j++){
                if(arr[i][j]==min){
                    for(int x=0;x<m;x++){
                        if(max<arr[x][j]){
                            max=arr[x][j];
                        }
                    }
                    if(min==max){
                        is_saddle=true;
                        std::cout<<min<<std::endl;
                        break;
                    }
                }
            }
        }
            if(is_saddle==false) std::cout<<"Impossible"<<std::endl;

    }
    return 0;
}