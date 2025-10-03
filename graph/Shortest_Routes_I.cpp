#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int>>>adj(n+1);
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<int>dist(n+1,1e18);
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int curd=it.first;
        int curn=it.second;
        if(dist[curn]<curd) continue;
        for(auto it:adj[curn])
        {
            if(curd+it[1]<dist[it[0]])
            {
                dist[it[0]]=curd+it[1];
                pq.push({curd+it[1],it[0]});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}