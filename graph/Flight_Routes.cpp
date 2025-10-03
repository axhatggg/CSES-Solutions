#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int inf=1e18;
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<vector<int>>>adj(n+1);
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<int>>dist(n+1,vector<int>(k,inf));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    dist[1][0]=0;
    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        int curd=cur.first;
        int curn=cur.second;
        if(curd>dist[curn][k-1]) continue;
        for(auto it:adj[curn])
        {
            int edw=it[1];
            int nbn=it[0];
            if(curd+edw<dist[nbn][k-1])
            {
                dist[nbn][k-1]=curd+edw;
                pq.push({curd+edw,nbn});
                sort(dist[nbn].begin(),dist[nbn].end());
            }
        }
    }
    for(int i=0;i<k;i++) cout<<dist[n][i]<<" ";
}