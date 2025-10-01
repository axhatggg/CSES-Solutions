#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& a,int cur,vector<int> &vis)
{
    vis[cur]=1;
    for(auto it:a[cur])
    if(vis[it]==0)
    dfs(a,it,vis);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1);
    int i1,i2;
    for(int i=0;i<m;i++)
    {
        cin>>i1>>i2;
        a[i1].push_back(i2);
        a[i2].push_back(i1);
    }
    vector<int>vis(n+1,0);
    int ans=0;
    queue<int>s;
    for(int i=1;i<=n;i++)
    if(vis[i]==0)
    {
        ans++;
        s.push(i);
        dfs(a,i,vis);
    }
    cout<<ans-1<<"\n";
    while(s.size()>1)
    {
        int v=s.front();
        s.pop();
        cout<<v<<" "<<s.front()<<"\n";
    }
}