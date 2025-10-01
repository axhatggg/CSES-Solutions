#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ln '\n'
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;

    ordered_set<int> children;
    for (int i = 1; i <= n; i++) // insert 1..n
        children.insert(i);

    int startPosition = 0;
    while (!children.empty())
    {
        startPosition %= children.size();
        int positionToRemove = (startPosition + k) % children.size();

        auto it = children.find_by_order(positionToRemove);
        cout << *it << " ";
        children.erase(it);

        startPosition = positionToRemove; // continue from next
    }
    cout << ln;
}
