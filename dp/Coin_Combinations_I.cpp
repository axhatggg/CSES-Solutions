/*
  ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define TEST(t) int t; cin>>t; while(t--) 
#define mod 1000000007
using namespace std;

// Print pair<T1, T2>
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << " " << p.second;
    return os;
}
 
// Print vector<T>
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& elem : v) {
        os << elem << " ";
    }
    return os;
}
// Print 2D vector<T>
template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (const auto& row : v) {
        for (const auto& elem : row) {
            os << elem << " ";
        }
        os << '\n';
    }
    return os;
}
// Print vector<pair<T1, T2>>
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const vector<pair<T1, T2>>& v) {
    for (const auto& p : v) {
        os << "(" << p.first << ", " << p.second << ") ";
    }
    return os;
}

signed main()
{
    fastIO;
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % mod;
        }
    }

    cout << dp[x] << '\n';
}