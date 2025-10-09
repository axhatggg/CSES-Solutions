#include<bits/stdc++.h>
using namespace std;
int dfs(int cur,vector<vector<int>> &adj,vector<int> &ans)
{
    int sub=0;
    for(auto it:adj[cur])
    {
        sub+=1+dfs(it,adj,ans);
    }
    return ans[cur]=sub;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    int par;
    for(int i=2;i<=n;i++)
    {
        cin>>par;
        adj[par].push_back(i);
    }
    vector<int>ans(n+1,0);
    int ch=dfs(1,adj,ans);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}