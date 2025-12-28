#include <stdio.h>
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        long long m, n;
        scanf("%lld %lld", &m, &n);
        
        if (gcd(m, n) == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}