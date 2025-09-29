#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,ans=0,c=0;
    for(int r=0;r<n;r++)
    {
        m[a[r]]++;
        c++;
        if(c>m.size())
        {
            m[a[l]]--;
            if(m[a[l]]==0) m.erase(a[l]);
            l++;
            c--;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}