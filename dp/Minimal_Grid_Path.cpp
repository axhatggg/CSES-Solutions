/*
  ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

signed main() {
    fastIO;
    int n;
    cin >> n;
    vector<vector<char> > a(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<bool> > vis(n, vector<bool>(n, false));
    vector<pair<int, int> > q;
    q.push_back({0, 0});
    vis[0][0] = true;

    string ans = "";
    ans += a[0][0];

    while (1) {
        vector<pair<int, int> > next;
        char mini = 'Z' + 1;

        for (auto p : q) {
            int x = p.first;
            int y = p.second;
            if (x + 1 < n && !vis[x + 1][y]) {
                mini = min(mini, a[x + 1][y]);
            }
            if (y + 1 < n && !vis[x][y + 1]) {
                mini = min(mini, a[x][y + 1]);
            }
        }

        if (mini == 'Z' + 1) break; 
        for (auto p : q) {
            int x = p.first;
            int y = p.second;
            if (x + 1 < n && !vis[x + 1][y] && a[x + 1][y] == mini) {
                vis[x + 1][y] = true;
                next.push_back({x + 1, y});
            }
            if (y + 1 < n && !vis[x][y + 1] && a[x][y + 1] == mini) {
                vis[x][y + 1] = true;
                next.push_back({x, y + 1});
            }
        }

        ans += mini;
        q = next;
    }

    cout << ans << "\n";
}
