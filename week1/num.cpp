#include <iostream>
#include <cmath>
using namespace std;
long long input;
int num;
int i;

int main(){
    cin>>input;
    num=(int)(log10(input))+1;
    const int Num = num;
    int result[Num];

    //数字存储循环
    for(;num>0;num--){
        result[num-1]=input/(pow(10,num-1));
        input-=result[num-1]*(pow(10,num-1));
    }

    //奇数偶数判断
    if(result[0]%2==0){
        if(Num%2==0){
            for(i=Num-1;i>-1;i-=2){
                cout<<result[i]<<" ";
            }

        }else{
            for(i=Num-2;i>-1;i-=2){
                cout<<result[i]<<" ";
            }
        }

    }else{
        if(Num%2!=0){
            for(i=Num-1;i>-1;i-=2){
                cout<<result[i]<<" ";
            }
            
        }else{
            for(i=Num-2;i>-1;i-=2){
                cout<<result[i]<<" ";
            }
        }
    }
    return 0;
}