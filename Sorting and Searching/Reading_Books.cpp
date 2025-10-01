#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    sort(a.begin(),a.end());
    if(s-a[n-1]<=a[n-1]) cout<<2*a[n-1];
    else cout<<s;
}