#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
bool dfs(vector<vector<int>> &adj,int cur,vector<int> &vis,int par)
{
    vis[cur]=1;
    for(auto it:adj[cur])
    {
        if(it!=par && vis[it]==1) {
            ans.push_back(it);
            ans.push_back(cur);
            return true;
        }
        else if(vis[it]==0)
        {
            if(dfs(adj,it,vis,cur)) {
                ans.push_back(cur);
                return true;
            }
        }
    }
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
        adj[b].push_back(a);
    }
    bool f=false;
    
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(adj,i,vis,-1))
            {
                f=true;
                break;
            }
        }
    }
    if(!f) cout<<"IMPOSSIBLE";
    else
    {
        int n=ans.size();
        for(int i=1;i<n;i++)
        {
            if(ans[i]==ans[0])
            {
                n=i+1;
                break;
            }
        }
        cout<<n<<"\n";
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    }
}