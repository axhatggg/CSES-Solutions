#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int inf=1e18;
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>>adj(n+1,vector<int>(n+1,inf));
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[b][a],c);
    }

    for(int via=1;via<=n;via++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adj[i][via]!=inf && adj[via][j]!=inf)
                {
                    if(adj[i][j]>adj[i][via]+adj[via][j]) adj[i][j]=adj[i][via]+adj[via][j];
                }
            }
        }
    }
    while(q--)
    {
        cin>>a>>b;
        if(a==b){
            cout<<"0\n";
            continue;
        }
        cout<<(adj[a][b]==inf?-1:adj[a][b])<<"\n";
    }
}