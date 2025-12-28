#include<iostream>
using namespace std;
#include<iomanip>

void TotalAverage(float score[],float n){
    float total=0,average=0;
    for(int i=0; i<n; i++){
        total += score[i];
    }
    average=total/n;
    cout<<total<<' ';
    cout<<fixed<<setprecision(1)<<average;
}


int main(){
    float m,n;
    cin>>m>>n;
    if(m>30||n>5){
        return 0;
    }

    
    for(int i=0; i<m; i++){
        float score[5];
        for(int j=0; j<n; j++){
            cin>>score[j];
        }
        TotalAverage(score,n);
        cout<<endl;
    }
    
    return 0;
}