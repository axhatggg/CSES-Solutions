#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj,int i,vector<int> &vis,int tf)
{
    vis[i]=tf;
    for(auto it:adj[i])
    {
        if(vis[it]==tf) return false;
        else if(vis[it]==-1)
        {
            if(!dfs(adj,it,vis,1-tf)) return false;
        }
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n+1,-1);
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==-1)
        {
            f=dfs(adj,i,vis,0);
            if(!f) break;
        }
    }
    if(!f) cout<<"IMPOSSIBLE";
    else
    {
        for(int i=1;i<=n;i++) cout<<vis[i]+1<<" ";
    }
}