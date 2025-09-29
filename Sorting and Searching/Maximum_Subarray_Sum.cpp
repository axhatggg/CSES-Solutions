#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long s=0;
    long long ans=LLONG_MIN;
    for(int i=0;i<n;i++)
    {
        s=s+a[i];
        ans=max(ans,s);
        if(s<0) s=0;
    }
    cout<<ans;
}