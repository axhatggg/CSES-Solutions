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
    int s=0;
    vector<int>a(n);
    for(int i=0;i<n;i++) {cin>>a[i];s+=a[i];}
    vector<bool>dp(s+1,false);
    dp[0]=true;
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=s;j>=0;j--)
        {
            if(j-a[i]>=0 && dp[j-a[i]]) {dp[j]=true;}
        }
    }
    // cout<<c<<"\n";
    for(int i=1;i<=s;i++) if(dp[i]) c++;
    cout<<c<<"\n";
    for(int i=1;i<=s;i++) if(dp[i]) cout<<i<<" ";
}