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
int minDistance(string word1, string word2) {
        int l1=word1.length(),l2=word2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            {
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    int ins=1+dp[i][j-1];
                    int rep=1+dp[i-1][j-1];
                    int del=1+dp[i-1][j];
                    dp[i][j]=min(ins,min(rep,del));
                }
            }
        }
        return dp[l1][l2];
    }
signed main()
{
    fastIO;
    string a,b;
    cin>>a>>b;
    cout<<minDistance(a,b);
}