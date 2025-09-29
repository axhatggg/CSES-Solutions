#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;
    cin>>x>>n;
    set<int>pts;
    multiset<int>len;
    pts.insert(0);
    pts.insert(x);
    len.insert(x);
    while(n--)
    {
        int v;
        cin>>v;
        auto it = pts.upper_bound(v);
        int r = *it;
        it--;
        int l = *it;
        len.erase(len.find(r - l));
        len.insert(v - l);
        len.insert(r - v);
        pts.insert(v);
        cout << *len.rbegin() << " ";
    }
}
