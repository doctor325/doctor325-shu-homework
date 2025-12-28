#include <bits/stdc++.h>
typedef unsigned long long ull;

ull step(ull itpt){
    ull otpt = 1;
    while(itpt > 0){
        otpt = otpt * (itpt % 10);
        itpt /= 10;
    }
    return otpt;
}
int main(){
    ull a,b,max = 0;
    std::cin>>a>>b;
    std::vector <ull> arr;
    arr.clear();
    for(ull i = a;i <= b;i++){
        ull coun = 0;
        ull temp = i;
        while(temp > 9){
            temp = step(temp);
            coun++;
        }
        if(coun == max){
            arr.push_back(i);
        }else if(coun > max){
            max = coun;
            arr.clear();
            arr.push_back(i);
        }
    }
    std::cout<<max<<std::endl;
    for(ull i = 0;i < arr.size();i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}