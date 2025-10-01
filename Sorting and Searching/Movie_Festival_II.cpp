#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>a[i][1]>>a[i][0];
    sort(a.begin(),a.end());
    int ans=0;
    multiset<int>ends;
    for(int i=0;i<k;i++) ends.insert(0);
    for(int i=0;i<n;i++)
    {
        auto it=ends.upper_bound(a[i][1]);
        if(it==ends.begin()) continue;
        it--;
        ends.erase(it);
        ends.insert(a[i][0]);
        ans++;
    }
    cout<<ans;
}