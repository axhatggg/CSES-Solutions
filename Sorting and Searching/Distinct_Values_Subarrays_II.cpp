#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    int l = 0;
    map<int, int> freq;

    for(int r = 0; r < n; ++r) {
        freq[a[r]]++;
        while(freq.size() > k) {
            freq[a[l]]--;
            if(freq[a[l]] == 0) {
                freq.erase(a[l]);
            }
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';
}