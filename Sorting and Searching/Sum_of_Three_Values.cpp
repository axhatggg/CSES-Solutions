#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>a[i][0];
    for(int i=0;i<n;i++) a[i][1]=i+1;
    sort(a.begin(),a.end());
    bool f=false;
    for(int i=0;i<n-2;i++)
    {
        int l=i+1,r=n-1;
        while(l<r)
        {
            if(a[l][0]+a[r][0]==x-a[i][0]){
                cout<<a[i][1]<<" "<<a[l][1]<<" "<<a[r][1];
                f=true;
                break;
            }
            else if(a[l][0]+a[r][0]<x-a[i][0]) l++;
            else r--;
        }
        if(f) break;
    }
    if(!f) cout<<"IMPOSSIBLE";
}