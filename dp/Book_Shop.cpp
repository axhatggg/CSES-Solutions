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
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    // cout<<f(a,b,x,n-1,n);
    // vector<vector<int>>dp(n,vector<int>(x+1));
    vector<int>pre(x+1);
    for(int i=0;i<=x;i++)
    {
        if(i>=a[0]) pre[i]=b[0];
        else pre[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        vector<int>cur(x+1);
        for(int j=0;j<=x;j++)
        {
            int tk=0;
            if(j>=a[i]) tk=b[i]+pre[j-a[i]];
            int nt=pre[j];
            cur[j]=max(tk,nt);
        }
        pre=cur;
    }
    // cout<<dp;
    cout<<pre[x];
}