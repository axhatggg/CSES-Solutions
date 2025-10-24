#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

signed main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        int exp = mod_pow(b, c, MOD - 1); 
        int ans = mod_pow(a, exp, MOD);
        cout << ans << "\n";
        
    }
}
