#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long v=a[n/2];
    long long ans=0ll;
    for(int i=0;i<n;i++) ans+=abs(a[i]-v);
    if(n%2==0)
    {
        long long ans2=0ll;
        for(int i=0;i<n;i++) ans2+=abs(a[i]-a[n/2 - 1]);
        cout<<min(ans,ans2);
    }
    else cout<<ans;
    
}