#include<iostream>
using namespace std;
#include<string>
#include<vector>

void MaxChar(string &str){
    char count='0';
    char max='0';
    char max_char;
    char results[2][52];
    int i=0;
    for(string::iterator it=str.begin(); it!=str.end(); it++){
        if(*it==*it++){
            count++;
        }
        if(*it!=*it++){
            results[0][i]=*it;
            results[1][i]=count;
            count='0';
        }
    }

    for(int i=0;i<52;i++){
        if(max<results[1][i]){
            max=results[1][i];
            max_char=results[0][i];
        }
    }
    cout<<max_char<<" "<<max<<endl;
}

int main(){
    int n;
    cin>>n;
    string str;
    for(int i=0; i<n; i++){
        cin>>str;
        MaxChar(str);
    }
    
    return 0;
}