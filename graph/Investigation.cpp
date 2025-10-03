#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    vector<int> dist(n + 1, 1e18);
    vector<int> path_counts(n + 1, 0);
    vector<int> min_edges(n + 1, 0);
    vector<int> max_edges(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    path_counts[1] = 1;
    pq.push({0, 1}); 
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) {
            continue;
        }

        for (auto& edge : adj[u])
        {
            int v = edge.first;
            int edw = edge.second;

            if (dist[v] > dist[u] + edw)
            {
                dist[v] = dist[u] + edw;
                path_counts[v] = path_counts[u];
                min_edges[v] = min_edges[u] + 1;
                max_edges[v] = max_edges[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + edw)
            {
                path_counts[v] = (path_counts[v] + path_counts[u]) % mod;
                min_edges[v] = min(min_edges[v], min_edges[u] + 1);
                max_edges[v] = max(max_edges[v], max_edges[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << path_counts[n] << " " << min_edges[n] << " " << max_edges[n] << "\n";
}

signed main()
{
 solve();
}