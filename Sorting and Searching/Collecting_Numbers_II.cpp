#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> pos(n + 1); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i; 
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i + 1] < pos[i]) {
            ans++;
        }
    }
    while (q--) {
        int q1, q2;
        cin >> q1 >> q2;
        q1--; 
        q2--;
        int el1 = a[q1];
        int el2 = a[q2];
        set<int> affected;
        if (el1 > 1) affected.insert(el1 - 1);
        if (el1 < n) affected.insert(el1);
        if (el2 > 1) affected.insert(el2 - 1);
        if (el2 < n) affected.insert(el2);
        for (int v : affected) {
            if (pos[v] > pos[v + 1]) {
                ans--;
            }
        }
        swap(a[q1], a[q2]);
        pos[el1] = q2;
        pos[el2] = q1;
        for (int v : affected) {
            if (pos[v] > pos[v + 1]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}