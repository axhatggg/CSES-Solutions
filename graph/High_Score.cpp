#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n, m;
    int inf=-4e18;
    cin >> n >> m;

    vector<vector<int>> edges(m,vector<int>(3)); 
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int> dist(n + 1, inf);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != inf && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    vector<int> affected;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != inf && dist[u] + w > dist[v]) {
            affected.push_back(v);
        }
    }

    vector<vector<int>> adj(n + 1);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
    }

    vector<int> vis(n + 1, 0);
    queue<int> q;
    for (int node : affected) {
        if (!vis[node]) {
            vis[node] = 1;
            q.push(node);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    if (vis[n]) cout << -1 << "\n";
    else cout << dist[n] << "\n";

    return 0;
}
