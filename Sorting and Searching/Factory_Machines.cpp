#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(int k,vector<int>& a,int m)
{
    int pro=0ll;
    for(auto it:a) {pro+=m/it;
    if(pro>=k) return true;}
    return pro>=k;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,h=LLONG_MAX;
    int ans=0;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(check(k,a,m)){
            ans=m;
            h=m-1ll;
        }
        else l=m+1ll;
    }
    cout<<ans;
}
