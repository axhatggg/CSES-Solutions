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
    int n;
    cin>>n;
    vector<int>dp(n+1,1e9);
    int i=n;
    dp[n]=0;
    while(i>=0)
    {
        if(dp[i]!=1e9)
        {int temp=i;
        while(temp>0)
        {
            int d=temp%10;
            dp[i-d]=min(dp[i-d],dp[i]+1);
            temp/=10;
        }}
        i--;
    }
    // cout<<dp;
    cout<<dp[0];
}