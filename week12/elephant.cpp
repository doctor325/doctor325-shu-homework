#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int results=n/5;
    if(n%5==0){
        cout<<results<<endl;
    }
    else{
        cout<<results+1<<endl;

    }
    return 0;
}