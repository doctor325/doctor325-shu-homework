#include<iostream>
using namespace std;
int main(){

int C;
 while (cin >> C){
long long ans = (C*C*C*C + 2*C + 3*C*C + 2*C*C*C) / 8;

 cout << ans << endl;

}


 return 0;

}