/*
 ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define TEST(t) int t; cin>>t; while(t--)
#define mod 1000000007
using namespace std;

vector<vector<int>> adj;
int diameter = 0;

int dfs(int u, int parent) {
    int longest = 0;
    int second_longest = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;
        int child_path_length = 1 + dfs(v, u);
        if (child_path_length > longest) {
            second_longest = longest;
            longest = child_path_length;
        } else if (child_path_length > second_longest) {
            second_longest = child_path_length;
        }
    }
    diameter = max(diameter, longest + second_longest);
    return longest;
}

signed main()
{
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << diameter << endl;
}