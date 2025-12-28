#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<cmath>
#include<vector>

int main(){
    int num;
    cin>>num;

    if(num<0) cout<<"fu ";
    num = abs(num);

    if(num == 0) {
        cout<<"ling";
        return 0;
    }
    
    vector<int> arr;
    while(num>0){
        arr.push_back(num%10);
        num /= 10;
    }

    for(int i= arr.size()-1 ; i >= 0; i--){
        switch(arr[i]){
            case 0: cout<<"ling"; break;
            case 1: cout<<"yi"; break;
            case 2: cout<<"er"; break;
            case 3: cout<<"san"; break;
            case 4: cout<<"si"; break;
            case 5: cout<<"wu"; break;
            case 6: cout<<"liu"; break;
            case 7: cout<<"qi"; break;
            case 8: cout<<"ba"; break;
            case 9: cout<<"jiu"; break;
        }
        if(i>0) cout<<" ";
    }
    return 0;
}