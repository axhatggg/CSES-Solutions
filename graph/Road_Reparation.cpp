#include <bits/stdc++.h>
#define int long long
using namespace std;
bool f;
int spanningTree(int V, vector<vector<vector<int>>> &adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> vis(V+1, 0);

    int ans = 0ll;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int nd = it.second;
        if (vis[nd])
            continue;
        ans += it.first;
        vis[nd] = 1;
        for (auto nb : adj[nd])
        {
            if (!vis[nb[0]])
                pq.push({nb[1], nb[0]});
        }
    }

    for(int i=1;i<=V;i++)
    {
        if(vis[i]) f=true;
        else
        {
            f=false;
            break;
        }
    }
    return ans;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>>adj(n+1);
    int u,v,c;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    int ans=spanningTree(n,adj);
    if(!f) cout<<"IMPOSSIBLE";
    else cout<<ans;
}