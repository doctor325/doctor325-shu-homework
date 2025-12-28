#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void Print(int num){
    cout<<num<<endl;
}

int main(){
    vector<int> v;  
    for(int i=0;i<5;i++){
        v.push_back(i);
    }

    //第一种遍历
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }

    //第二种遍历
    // vector<int>::iterator ItBegin=v.begin();
    // vector<int>::iterator ItEnd=v.end();

    // while(ItBegin != ItEnd){
    //     cout<<*ItBegin<<endl;
    //     ItBegin++;
    // }

    //第三种遍历
    // for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    //     cout<<*it<<endl;

    // }


    for_each(v.begin(),v.end(),Print);


    return 0;
}