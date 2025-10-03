#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{   
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<vector<int>> dist(n + 1, vector<int>(2, 1e18));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, coupon_used] = pq.top();
        pq.pop();
        if (d > dist[u][coupon_used]) {
            continue;
        }
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (coupon_used == 0) {
                if (dist[v][0] > d + w) {
                    dist[v][0] = d + w;
                    pq.push({dist[v][0], v, 0});
                }
                if (dist[v][1] > d + w / 2) {
                    dist[v][1] = d + w / 2;
                    pq.push({dist[v][1], v, 1});
                }
            }
            else {
                if (dist[v][1] > d + w) {
                    dist[v][1] = d + w;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]) << endl;
}