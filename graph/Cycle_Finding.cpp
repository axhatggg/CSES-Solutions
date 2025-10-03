/*
 ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define TEST(t) int t; cin>>t; while(t--)
#define mod 1000000007
using namespace std;

// Print pair<T1, T2>
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
 os << p.first << " " << p.second;
 return os;
}
 
// Print vector<T>
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
 for (const auto& elem : v) {
 os << elem << " ";
 }
 return os;
}
// Print 2D vector<T>
template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
 for (const auto& row : v) {
 for (const auto& elem : row) {
 os << elem << " ";
 }
 os << '\n';
 }
 return os;
}
// Print vector<pair<T1, T2>>
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const vector<pair<T1, T2>>& v) {
 for (const auto& p : v) {
 os << "(" << p.first << ", " << p.second << ") ";
 }
 return os;
}

signed main()
{
 fastIO;
 // TEST(t) // Assuming a single test case as per the problem format
 {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // CHANGE: Initialize all distances to 0 to find any negative cycle,
    // not just those reachable from node 1.
    vector<int> dist(n + 1, 0); 
    vector<int> parent(n + 1, -1);
    
    // We need to relax up to n times. The n-th time is for detection.
    // The last node updated in the n-th relaxation will be our starting point.
    int cycle_start_node = -1;
    for (int i = 1; i <= n; i++) {
        cycle_start_node = -1; // Reset on each pass
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                // If an update happens on the n-th pass, we've found our cycle.
                if (i == n) {
                    cycle_start_node = v;
                }
            }
        }
    }

    if (cycle_start_node == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // Backtrack n times to land safely inside the cycle,
        // as cycle_start_node could be on a "tail" path.
        int node_in_cycle = cycle_start_node;
        for (int i = 0; i < n; ++i) {
            node_in_cycle = parent[node_in_cycle];
        }

        vector<int> cycle_path;
        int current_node = node_in_cycle;
        while (true) {
            cycle_path.push_back(current_node);
            current_node = parent[current_node];
            if (current_node == node_in_cycle) {
                cycle_path.push_back(current_node);
                break;
            }
        }
        
        reverse(cycle_path.begin(), cycle_path.end());
        // Using your template's vector printer
        cout << cycle_path << "\n";
    }
 }
}