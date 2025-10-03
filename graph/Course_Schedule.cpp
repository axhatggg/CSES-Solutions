#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>ind(n+1,0);
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        ind[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    if(ind[i]==0)
    q.push(i);
    
    vector<int>ans;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(auto it:adj[cur])
        {
            ind[it]--;
            if(ind[it]==0) 
            q.push(it);
        }
    }
    if(ans.size()!=n) cout<<"IMPOSSIBLE";
    else for(auto it:ans) cout<<it<<" ";
}