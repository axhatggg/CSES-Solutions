#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    sort(a.begin(),a.end());
    int ans=0ll;
    int cur=0ll;
    for(int i=0;i<n;i++)
    {
        cur+=a[i][0];
        ans+=a[i][1]-cur;
    }
    cout<<ans;
}