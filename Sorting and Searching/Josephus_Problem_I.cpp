#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==1) {cout<<1; return 0;}
    vector<vector<int>>a(n+1,vector<int>(2,0));
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            a[i][0]=2;
            a[i][1]=n;
        }
        else if(i==n)
        {
            a[i][0]=1;
            a[i][1]=n-1;
        }
        else
        {
            a[i][0]=i+1;
            a[i][1]=i-1;
        }
    }
    int cur=2;
    while(a[a[cur][0]][0]!=cur)
    {
        cout<<cur<<" ";
        a[a[cur][1]][0]=a[cur][0];
        a[a[cur][0]][1]=a[cur][1];
        cur=a[a[cur][0]][0];
    }
    cout<<cur<<" "<<a[cur][0];
}