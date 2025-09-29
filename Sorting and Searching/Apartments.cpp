#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<pair<int,int>> rngs(n);
    for(int i=0;i<n;i++) rngs[i]={a[i]-k,a[i]+k};
    int aptpt=0;
    int rngpt=0;
    int ans=0;
    while(aptpt<m && rngpt<n)
    {
        while(aptpt<m && b[aptpt]<rngs[rngpt].first) aptpt++;
        if(aptpt==m) break;
        while(rngpt<n && rngs[rngpt].second<b[aptpt]) rngpt++;
        if(rngpt==n) break;
        if(b[aptpt]>=rngs[rngpt].first && b[aptpt]<=rngs[rngpt].second)
        {
            ans++;
            aptpt++;
            rngpt++;
        }
    }
    cout<<ans;
}