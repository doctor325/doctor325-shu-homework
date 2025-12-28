#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
    int n,k,mex;
    cin>>n>>k;
    vector<int> a;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    auto it=find(a.begin(),a.end(),k);
    if(it!=a.end()){
        int m=count(a.begin(),a.end(),k);
        set<int> s(a.begin(),a.end());
        auto It=find(s.begin(),s.end(),k);
        int M=k-distance(s.begin(),It)+1;

        if(m<=M){
            mex=m;
        }
        else{
            mex=M;
        }

    }
    else{
        a.push_back(k);
        sort(a.begin(),a.end());
        set<int> s(a.begin(),a.end());
        auto It=find(s.begin(),s.end(),k);
        mex=k-distance(s.begin(),It);
    }


    cout<<mex<<endl;
}
    return 0;
}