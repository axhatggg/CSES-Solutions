#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int>m;
    m[0]=1;
    int cur=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cur+=a[i];
        ans+=m[((cur%n)+n)%n];
        m[((cur%n)+n)%n]++;
    }
    cout<<ans;
}