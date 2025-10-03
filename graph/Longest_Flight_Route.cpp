#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
int n, m;
cin >> n >> m;
vector<vector<int>> adj(n + 1);
vector<int> ind(n + 1, 0);
for (int i = 0; i < m; ++i) {
int u, v;
cin >> u >> v;
adj[u].push_back(v);
ind[v]++;
}


queue<int> q;
for (int i = 1; i <= n; ++i) {
    if (ind[i] == 0) {
        q.push(i);
    }
}

vector<int> topo;
while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for (int v : adj[u]) {
        ind[v]--;
        if (ind[v] == 0) {
            q.push(v);
        }
    }
}


vector<int> dist(n + 1, 0);
vector<int> parent(n + 1, 0);

dist[1] = 1;

for (int u : topo) {
    if (dist[u] == 0) {
        continue;
    }

    for (int v : adj[u]) {
        if (dist[v] < dist[u] + 1) {
            dist[v] = dist[u] + 1;
            parent[v] = u;
        }
    }
}

if (dist[n] == 0) {
    cout << "IMPOSSIBLE\n";
} else {
    cout << dist[n] << "\n";
    vector<int> path;
    int curr = n;
    while (curr != 0) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    for(auto it: path) cout<<it<<" ";
}
}
signed main()
{
  solve();
}