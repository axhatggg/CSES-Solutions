#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int mod=1e9+7;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> ind(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ind[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    if (ind[i] == 0)
    q.push(i);

    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u])
        {
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }

    vector<int> ways(n + 1, 0);
    vector<int> parent(n + 1, 0);
    ways[1] = 1ll;
    for (int u : topo)
    {
        if (ways[u] == 0) continue;
        for (int v : adj[u])
        {
            ways[v] = (ways[v]%mod + ways[u]%mod)%mod;
            parent[v] = u;
        }
    }
    cout << ways[n]%mod << "\n";
}
signed main()
{
    solve();
}
