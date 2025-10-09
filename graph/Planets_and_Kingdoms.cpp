#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj,
         stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}

void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT, int kingdom)
{
    vis[node] = kingdom;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adjT,kingdom);
        }
    }
}

pair<int,vector<int>> kosaraju(vector<vector<int>> &adj,int n)
{
    vector<int> vis(n+1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    vector<vector<int>> adjT(n+1);
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs3(node, vis, adjT,scc);
        }
    }
    return {scc,vis};
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    auto ans=kosaraju(adj,n);
    cout<<ans.first<<"\n";
    vector<int>pans=ans.second;
    for(int i=1;i<=n;i++) cout<<pans[i]<<" ";

}