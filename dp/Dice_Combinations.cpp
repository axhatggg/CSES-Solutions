/*
  ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define TEST(t) int t; cin>>t; while(t--) 
using namespace std;
signed main()
{
    fastIO;
    int n;
    cin>>n;
    int mod=1e9+7;
    vector<int>dp(1e6+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    if(n<=6) cout<<dp[n];
    else
    {
        for(int i=7;i<=n;i++)
        {
            dp[i]=0;
            for(int j=i-1;j>=i-6;j--)
            dp[i]+=dp[j]%mod;
            dp[i]=dp[i]%mod;
        }
        
        cout<<dp[n];
    }
    
}