#include<iostream>
#include<algorithm>
#include<vector>
int main(){
    int T;
    std::cin>>T;
    while(T--){
        int n,m,k;
        std::cin>>n>>m>>k;
        // int arr[20][10];
        std::vector<std::vector<int>> arr(n);
        for(int i=0;i<n;i++){
            int add_n=0;
            for(int j=0;j<m;j++){
                int temp=0;
                std::cin>>temp;
                arr[i].push_back(temp);
                add_n+=arr[i][j];
            }
            arr[i].push_back(add_n);
        }
    std::sort(arr.begin(), arr.end(),
     [](const std::vector<int>& x, const std::vector<int>& y) {
         return x.back() > y.back();
     });
            
        
        for(int i=0;i<m;i++){
            std::cout<<arr[k-1][i];
            if(i<m-1) std::cout<<" ";
        }
    }
    return 0;
}