#include<iostream>
#include<set>


int main(){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::set<int> odd;
        std::set<int> even;
        for(int i=0; i<n; i++){
            int temp;
            std::cin>>temp;
            if(temp%2==0) even.insert(temp);
            else odd.insert(temp);
        }
        for(auto i=odd.begin(); i!=odd.end(); i++){
            std::cout<<*i<<" ";
        }
        int count=0;
        for(auto i=even.begin(); i!=even.end(); i++){
        std::cout<<*i;
        count++;
        if(count<even.size()) std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}