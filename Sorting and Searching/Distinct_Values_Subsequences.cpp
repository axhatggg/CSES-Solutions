#include<bits/stdc++.h>
using namespace std;

int main() {
    long long mod = 1e9 + 7;
    int n;
    cin >> n;
    int inp;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        m[inp]++;
    }
    long long ans = 1;
    for (auto it : m) {
        ans = (ans * (it.second + 1)) % mod;
    }
    cout << (ans - 1 + mod) % mod;
}