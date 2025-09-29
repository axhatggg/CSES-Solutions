// agar x-1 tak sara number banana possible hai toh 
// agar a[i]<=x mila toh matlab ye value ko leke aur appropiate minus mei leke x bhi bana skte 
// aur x ab a[i]+x ho jaega kyuki waha tak sab bana skte honge humlog
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long ans=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>ans) break;
        ans+=a[i];
    }
    cout<<ans;
}