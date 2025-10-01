#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(3));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    for(int i=0;i<n;i++) a[i][2]=i;
    sort(a.begin(),a.end());
    int cur=1;
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
    mini.push({a[0][1],cur});
    vector<int>ans2(n);
    ans2[a[0][2]]=1;
    for(int i=1;i<n;i++)
    {
        if(a[i][0]>mini.top().first)
        {
            auto it=mini.top();
            mini.pop();
            ans2[a[i][2]]=it.second;
            mini.push({a[i][1],it.second});
        }
        else
        {
            cur++;
            ans2[a[i][2]]=cur;
            mini.push({a[i][1],cur});
        }
    }
    cout<<cur<<"\n";
    for(int i=0;i<n;i++)
    cout<<ans2[i]<<" ";
}