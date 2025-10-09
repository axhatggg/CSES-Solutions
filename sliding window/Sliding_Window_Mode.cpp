#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> freq;
    for (int i = 0; i < m; i++)
    {
        freq[a[i]]++;
    }
    set<pair<int, int>> help;
    for (auto it : freq)
    {
        int el = it.first;
        int f = it.second;
        help.insert({f, -el});
    }

    int c;
    for (int i = m; i < n; i++)
    {
        auto it = *(help.rbegin());
        cout << -(it.second) << " ";
        int rel = i - m;
        c = freq[a[rel]];
        help.erase({c, -a[rel]});
        freq[a[rel]]--;
        help.insert({c-1, -a[rel]});


        c=freq[a[i]];
        help.erase({c, -a[i]});
        freq[a[i]]++;
        help.insert({c+1, -a[i]});


    }
    
    auto it = *(help.rbegin());
    cout << -(it.second) << " ";

}