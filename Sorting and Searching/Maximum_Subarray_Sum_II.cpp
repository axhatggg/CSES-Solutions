#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<int> p(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + x[i];
    }

    int maxSum = -4e14;
    deque<int> dq;
    for(int k = a; k <= n; ++k) {
        int idx_to_add = k - a;
        while(!dq.empty() && p[dq.back()] >= p[idx_to_add]) {
            dq.pop_back();
        }
        dq.push_back(idx_to_add);
        if(!dq.empty() && dq.front() < k - b) {
            dq.pop_front();
        }
        if(!dq.empty()){
            maxSum = max(maxSum, p[k] - p[dq.front()]);
        }
    }

    cout << maxSum << endl;
}