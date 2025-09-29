#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>a[i][1]>>a[i][0];
    sort(a.begin(),a.end());
    int ce=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i][1]>=ce){
            ans++;
            ce=a[i][0];
        }
    }
    cout<<ans;
}