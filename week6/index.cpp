#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int main(){
    unsigned long num;
    cin>>num;

    if(num<=2||num>=pow(2,31)){
        return 0;
    }
    
    vector<vector<int> > win(2,vector<int>(31));
    bool found=false;

    for(int index=1;index<31;index++){
        unsigned long range=1;
        unsigned long temp=0;

        do{
            temp += pow(range,index);
            range++;
        }while(temp<num);
        if(temp==num){
        win[0][index]=index;
        win[1][index]=range;
        found=true;
        }
    }

    if(!found){
        cout<<"Imposible for "<<num<<"."<<endl;
    }
    else{
        int max_index = win[0][0];
        int max_range = win[1][0];
        for (int i = 0; i <= 31; i++)
        {
            if (win[0][i] > max_index)
            {
                max_index = win[0][i];
                max_range = win[1][i];
            }
        }
        for(int i=1;i<max_range;i++){
            cout<<i<<"^"<<max_index;
            if (i < max_range - 1)
            {
                cout << "+";
            }
        }
        cout<<endl;
    }
    return 0;
}