#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
signed main()
{
    fastIO;
    int n, q;
    cin >> n >> q;
    const int m = 31;
    vector<vector<int>> spt(m, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> spt[0][i];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        
        for (int i = 0; i < m; i++) {
            if (k & (1LL << i)) {
                x = spt[i][x];
            }
        }
        cout << x << "\n";
    }
}