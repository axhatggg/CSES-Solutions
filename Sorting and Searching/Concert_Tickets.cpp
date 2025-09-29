#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    multiset<int>ms;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ms.insert(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        auto it=ms.upper_bound(b[i]);
        if(it==ms.begin()) cout<<"-1\n";
        else
        {
            it--;
            cout<<*it<<"\n";
            ms.erase(it);
        }
    }
    
}