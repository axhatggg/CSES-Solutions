#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(int m,int k,int n,vector<int>& a)
{
    int seg=1;
    int cur=0;
    for(int i=0;i<n;i++)
    {
        cur+=a[i];
        if(seg>k) return false;
        if(cur>m)
        {
            i--;
            cur=0;
            seg++;
        }
    }
    return true;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int h=0,l=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        l=min(l,a[i]);
        h+=a[i];
    }
    int ans;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(check(m,k,n,a))
        {
            ans=m;
            h=m-1;
        }
        else l=m+1;
    }
    cout<<ans;
}