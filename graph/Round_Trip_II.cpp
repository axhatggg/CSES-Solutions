#include<bits/stdc++.h>
using namespace std;
int cyclenode;
bool dfs(vector<vector<int>> &adj,int cur,vector<int> &vis,vector<int> &path,vector<int> &par)
{
    vis[cur]=1;
    path[cur]=1;
    for(auto it:adj[cur])
    {
        if(vis[it]==1 && path[it]==1) {
            cyclenode=it;
            par[it]=cur;
            return true;
        }
        else if(vis[it]==1) continue;
        else if(vis[it]==0)
        {
            par[it]=cur;
            if(dfs(adj,it,vis,path,par)) {
                return true;
            }
        }
    }
    path[cur]=0;
    return false;
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
    }
    bool f=false;
    vector<int>vis(n+1,0);
    vector<int>path(n+1,0);
    vector<int>par(n+1,0);
    
    for(int i=1;i<=n;i++)
    {
        // cout<<i<<"\n";
        if(vis[i]==0 && dfs(adj,i,vis,path,par))
        {
            f=true;
            break;
        }
        // cout<<i<<"\n";
    }
    if(!f) cout<<"IMPOSSIBLE";
    else
    {
        // cout<<"here\n";
        // for(auto it:par) cout<<it<<" ";
        vector<int>ans;
        int cur=cyclenode;
        ans.push_back(cur);
        cur=par[cur];
        while(cur!=cyclenode)
        {
            ans.push_back(cur);
            cur=par[cur];
        }
        ans.push_back(cur);
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(auto it:ans) cout<<it<<" ";
    }
}