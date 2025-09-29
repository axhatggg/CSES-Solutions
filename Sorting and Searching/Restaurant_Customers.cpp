#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>a;
    int v1,v2;
    for(int i=0;i<n;i++)
    {
        cin>>v1>>v2;
        a.push_back({v1,1});
        a.push_back({v2,-1});
    }
    sort(a.begin(),a.end());
    int cur=0;
    int ans=0;
    for(auto it:a)
    {
        cur+=it[1];
        ans=max(ans,cur);
    }
    cout<<ans;
}