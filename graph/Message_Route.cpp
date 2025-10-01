#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n+1,0);
    queue<int>q;
    q.push(1);
    vis[1]=1;
    bool f=false;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(cur==n)
        {
            f=true;
            break;
        }
        for(auto it:adj[cur])
        if(vis[it]==0)
        {
            vis[it]=cur;
            q.push(it);
        }
    }
    if(!f)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {vector<int>ans;
    int cur=n;
    while(cur!=1)
    {
        ans.push_back(cur);
        cur=vis[cur];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()+1<<"\n 1 ";
    for(auto it:ans) cout<<it<<" ";}
}