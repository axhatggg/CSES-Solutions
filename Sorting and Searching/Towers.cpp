#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    multiset<int>s;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        auto it=s.upper_bound(a[i]);
        if(it==s.end()) ans++;
        else s.erase(it);
        s.insert(a[i]);
    }
    cout<<ans;
}