#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    vector<vector<int>>b(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        b[i][0]=a[i][1];
        b[i][1]=a[i][0];
    }
    sort(b.begin(),b.end());

    map<pair<int,int>,int>ans1;
    int startMin=INT_MAX;
    for(int i=n-1;i>=0;i--)
    {
        if(startMin<=b[i][1])
        {
            ans1[{b[i][1],b[i][0]}]=1;
            continue;
        }
        if(i!=0 && b[i-1][0]==b[i][0])
        {
            ans1[{b[i][1],b[i][0]}]=1;
            startMin=b[i][1];
            continue;
        }
        ans1[{b[i][1],b[i][0]}]=0;
        startMin=b[i][1];
    }

    map<pair<int,int>,int>ans2;
    int startMax=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(startMax>=b[i][1])
        {
            ans2[{b[i][1],b[i][0]}]=1;
            continue;
        }
        if(i!=n-1 && b[i+1][0]==b[i][0])
        {
            ans2[{b[i][1],b[i][0]}]=1;
            startMax=b[i][1];
            continue;
        }
        ans2[{b[i][1],b[i][0]}]=0;
        startMax=b[i][1];
    }

    for(int i=0;i<n;i++) cout<<ans2[{a[i][0],a[i][1]}]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<ans1[{a[i][0],a[i][1]}]<<" ";
}