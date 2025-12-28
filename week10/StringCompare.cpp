#include<iostream>
#include<string>
using namespace std;

void CompareString(string &s1,string &s2){
    int result=s1.compare(s2);
    cout<<result<<endl;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    CompareString(s1,s2);
    return 0;
}