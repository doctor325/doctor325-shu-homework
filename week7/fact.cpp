#include <iostream>
#include<iomanip>
using namespace std;

using ll = long long;

ll Fact(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*Fact(n-1);
}


int main()
{
    int n;
   //cin >> n;

    if(cin>>n){
        for (int i = 2; i <= n; i += 2) { 
            ll result = Fact(i);
            cout << i << "! = " <<fixed<<setprecision(0)<< result << endl;
        }
    }

    return 0;
}
