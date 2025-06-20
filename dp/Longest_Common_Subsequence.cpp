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
int longestCommonSubsequence(vector<int> &t1, vector<int> &t2) {
        int n1=t1.size();
        int n2=t2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,0));
        bool f=false;
        for(int i=0;i<n2;i++)
        {
            if(f) dp[0][i]=1;
            else if(t2[i]==t1[0])
            {
                f=true;
                dp[0][i]=1;
            }
            else dp[0][i]=0;
        }
        f=false;
        for(int i=0;i<n1;i++)
        {
            if(f) dp[i][0]=1;
            else if(t1[i]==t2[0])
            {
                f=true;
                dp[i][0]=1;
            }
            else dp[i][0]=0;
        }
        for(int i=1;i<n1;i++)
        {
            for(int j=1;j<n2;j++)
            {
                if(t1[i]==t2[j])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    int c1=dp[i-1][j];
                    int c2=dp[i][j-1];
                    dp[i][j]=max(c1,c2);
                }
            }
        }
        vector<int>ans;
        int i=n1-1,j=n2-1;
        while(i>=0 && j>=0)
        {
            if(t1[i]==t2[j]){
                ans.push_back(t1[i]);
                i--;j--;
            }
            else if(i==0 || j==0)
            {
                if(i==0 && j==0){
                    if(t1[0]==t2[0]){
                        ans.push_back(t1[0]);
                        
                    }
                    break;
                }
                if(i==0)
                {
                    if(t1[i]==t2[j]) ans.push_back(t1[i]);
                    j--;
                }
                else
                {
                    if(t1[i]==t2[j]) ans.push_back(t1[i]);
                    i--;
                }
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        reverse(ans.begin(),ans.end());
        
        cout<<dp[n1-1][n2-1]<<"\n";
        cout<<ans<<"\n";
        return dp[n1-1][n2-1];
    }
signed main()
{
    fastIO;
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int ch=longestCommonSubsequence(a,b);
}