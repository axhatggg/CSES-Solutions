/*
  ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
using namespace std;


int modinv(int a) {
    int res = 1, b = mod - 2;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int perfectSum(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    if (arr[0] <= k) dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int nt = dp[i - 1][j];
            int t = (arr[i] <= j) ? dp[i - 1][j - arr[i]] : 0;
            dp[i][j] = (t + nt) % mod;
        }
    }
    return dp[n - 1][k];
}

signed main() {
    fastIO;
    int n;
    cin >> n;
    int s = (n * (n + 1)) / 2;

    if (s % 2 != 0) {
        cout << 0;
    } else {
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = i + 1;
        int totalWays = perfectSum(a, s / 2);
        cout << (totalWays * modinv(2)) % mod; 
    }
}
