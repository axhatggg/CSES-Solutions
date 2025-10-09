/*
 ~ Akshat Gupta ~
*/
#include <bits/stdc++.h>
#define int long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define TEST(t) \
    int t;      \
    cin >> t;   \
    while (t--)
#define mod 1000000007
using namespace std;

// Print pair<T1, T2>
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << " " << p.second;
    return os;
}

// Print vector<T>
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (const auto &elem : v)
    {
        os << elem << " ";
    }
    return os;
}
// Print 2D vector<T>
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (const auto &row : v)
    {
        for (const auto &elem : row)
        {
            os << elem << " ";
        }
        os << '\n';
    }
    return os;
}
// Print vector<pair<T1, T2>>
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const vector<pair<T1, T2>> &v)
{
    for (const auto &p : v)
    {
        os << "(" << p.first << ", " << p.second << ") ";
    }
    return os;
}

const int N = 200005;
vector<int> adj[N];
int dp[N][2]; 

void dfs(int u, int p)
{
 
    dp[u][0] = 0;
    dp[u][1] = 0;

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
    }

    int sum_of_max_from_children = 0;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        sum_of_max_from_children += max(dp[v][0], dp[v][1]);
    }
    dp[u][0] = sum_of_max_from_children;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        int sum_from_others = sum_of_max_from_children - max(dp[v][0], dp[v][1]);
        int current_match_val = 1 + dp[v][0] + sum_from_others;
        dp[u][1] = max(dp[u][1], current_match_val);
    }
}

signed main()
{
    fastIO;
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
}