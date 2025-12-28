#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<double> N;
    double n=0;
    while(cin>>n){
        if(n<1||n>2){
            break;
        }
        N.push_back(n);
    }


    for(int i=0;i<N.size();++i){
        double wang=100,ming=100;
            int count=0;
        while(ming < N[i]*wang){
            count++;
            ming *=1.001;
            if(count%5==1||count%5==2||count%5==3){
                wang *=1.002;
            }
            else {wang *=0.999;}
            
        }
        cout<<count<<" ";

    }
    
    return 0;
}