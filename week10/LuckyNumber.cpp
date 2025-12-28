#include<iostream>
using namespace std;
#include<string>

void LuckyNumber(string &str){
    char max='0';
    char max_number='0';
    char temp='0';
    
    for(char i='0';i<'9';i++){
        char count='0';
        for(string::iterator it=str.begin(); it!=str.end(); it++){
            if(*it==i){
                count++;
            }
            temp=count;
        }
        if(max_number<temp){
            max_number=temp;
            max=i;
        }
        else if(max_number==count){
            if(max<i){
                max=i;
            }
        }
    }
    cout<<max<<endl;
}

int main(){
    string num;
    cin>>num;

    LuckyNumber(num);
    return 0;
}