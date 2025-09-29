#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]=i;
    }
    int ans=1;
    int prev=m[1];
    for(int i=2;i<=n;i++)
    {
        if(m[i]<prev) ans++;
        prev=m[i];
    }
    cout<<ans;
}