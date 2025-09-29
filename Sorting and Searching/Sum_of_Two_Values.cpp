#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        a[i][1]=i+1;
    }
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    bool f=false;
    while(l<r)
    {
        if(a[l][0]+a[r][0]==x)
        {
            f=true;
            cout<<a[l][1]<<" "<<a[r][1];
            break;
        }
        else if(a[l][0]+a[r][0]<x) l++;
        else r--;
    }
    if(!f) cout<<"IMPOSSIBLE";
}