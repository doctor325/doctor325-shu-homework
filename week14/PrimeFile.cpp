#include<iostream>
#include<iomanip>
#include<fstream>

bool IsPrime(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    int n;
    int sum=0;
    int count=0;

    while(fin>>n){
        bool isprime=IsPrime(n);
        if(isprime){
            sum+=n;
            count++;
        }
    }

    double result=(double)sum/count;
    fout<<std::fixed<<std::setprecision(2)<<result<<std::endl;

    return 0;
}