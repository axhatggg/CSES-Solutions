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

const int N = 2e5 + 5;
vector<int> adj[N];
int sz[N];
int ans[N];
int n;


void dfs1(int u, int p, int d) {
    sz[u] = 1;
    ans[1] += d; 
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        // Rerooting formula
        ans[v] = ans[u] + n - 2 * sz[v];
        dfs2(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    fastIO;
    solve();
    return 0;
}