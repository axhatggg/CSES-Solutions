#include<bits/stdc++.h>
using namespace std;
int upar(vector<int> &par,int u)
{
    if(par[u]==u) return u;
    return par[u]=upar(par,par[u]);
}
void ubs(vector<int> &siz,vector<int> &par,int u,int v)
{
    int uu=upar(par,u);
    int uv=upar(par,v);
    if(uu==uv) return;
    if(siz[uu]>siz[uv]) swap(uu,uv);
    par[uu]=uv;
    siz[uv]+=siz[uu];
}
int main()
{
    int n,q;
    cin>>n>>q;
    int comp=n;
    int maxs=1;
    vector<int>par(n+1);
    for(int i=1;i<=n;i++) par[i]=i;
    vector<int>siz(n+1,1);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int uu=upar(par,u);
        int uv=upar(par,v);
        if(uu==uv)
        {
            maxs=max(maxs,siz[uu]);
        }
        else
        {
            comp--;
            ubs(siz,par,uu,uv);
            int ch=upar(par,uu);
            maxs=max(maxs,siz[ch]);
        }
        cout<<comp<<" "<<maxs<<"\n";
    }
}