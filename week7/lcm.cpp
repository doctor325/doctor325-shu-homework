#include<iostream>
using namespace std;
#include<vector>

using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    int t;
    cin >> t;


    vector<ll> niumo;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n < 2 || n>20) {
            return 0;
        }
        

        vector<ll> nima(n);
        for (int j = 0; j < n; j++) {
            cin >> nima[j];
            if (nima[j] < 1 || nima[j]>100000) {
                return 0;
            }
        }

        ll result = nima[0];
        for (int j = 1; j < n; j++) {
            result = lcm(result, nima[j]);
        }
        niumo.push_back(result);
    }

    for (vector<ll>::iterator it = niumo.begin(); it != niumo.end(); it++) {
        cout << *it << endl;

    }
    return 0;
}