#include <bits/stdc++.h>
#define int long long
using namespace std;
void bfs(int start, int n, vector<vector<int>>& adj, vector<int>& dist) {
    dist.assign(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
signed main()
{
    int n;
    cin >> n;
    if (n == 1) {cout<<"0"; return 0;}
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist_from_end1, dist_from_end2;
    bfs(1, n, adj, dist_from_end1);
    int end1 = 1;
    for (int i = 1; i <= n; ++i) {
        if (dist_from_end1[i] > dist_from_end1[end1]) {
            end1 = i;
        }
    }

    
    bfs(end1, n, adj, dist_from_end1);
    int end2 = 1;
    for (int i = 1; i <= n; ++i) {
        if (dist_from_end1[i] > dist_from_end1[end2]) {
            end2 = i;
        }
    }
    bfs(end2, n, adj, dist_from_end2);
    for (int i = 1; i <= n; ++i) {
        cout << max(dist_from_end1[i], dist_from_end2[i]) << (i == n ? "" : " ");
    }
}