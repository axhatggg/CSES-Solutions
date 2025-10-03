#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    int u,v;
    vector<vector<int>>edges(m,vector<int>(2));
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        edges[i][0]=u;
        edges[i][1]=v;
        adj[u].push_back(v);
    }
    vector<int>vis(n+1,0);
    queue<int>q;
    q.push(1);
    
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        vis[cur]=1;
        for(auto it:adj[cur])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    bool f=true;
    int ind;
    for(int i=1;i<=n;i++)
    if(!vis[i])
    {
        f=false;
        ind=i;
        break;
    }

    if(!f) cout<<"NO\n"<<1<<" "<<ind;
    else
    {
        vector<vector<int>>adjT(n+1);
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adjT[v].push_back(u);
        }
        vector<int>vist(n+1,0);
        queue<int>qt;
        qt.push(1);
        
        while(!qt.empty())
        {
            int cur=qt.front();
            qt.pop();
            vist[cur]=1;
            for(auto it:adjT[cur])
            {
                if(!vist[it])
                {
                    vist[it]=1;
                    qt.push(it);
                }
            }
        }
        for(int i=1;i<=n;i++)
        if(!vist[i])
        {
            f=false;
            ind=i;
            break;
        }

        if(!f) cout<<"NO\n"<<ind<<" "<<1;
        else cout<<"YES";
    }
}