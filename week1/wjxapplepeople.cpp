#include <iostream>
using namespace std;

int n;
int i,j,k;
int judge,stop,count;
int day,day_empty,day_out;
int main(){
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        arr[i]=i+1;
        judge+=arr[i];     
    }
    while(judge!=0){
        stop=0;
        day++;
        for(j=0;stop==0&&j<n;j++){
            if(arr[j]!=0){
                stop=1;
                count=3;
                for(k=j;k<n;k++){
                    if(arr[k]==0){
                        count--;
                    }
                    if(count==3){
                        arr[k]=0;
                        count=0;
                    }
                    count++;
                    if(k==n-1){
                        day_out=day;
                    }
                }
            }
        }
        judge=0;
        for(i=0;i<n;i++){
            judge+=arr[i];
        }
    }
    day_empty=day;
    cout<<day_empty<<" "<<day_out<<endl;
    return 0;
}