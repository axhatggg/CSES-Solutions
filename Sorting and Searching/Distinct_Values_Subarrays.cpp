#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long>a(n);
    for(long long i=0;i<n;i++) cin>>a[i];
    map<long long,long long>m;
    long long l=0;
    long long ans=0;
    for(long long r=0;r<n;r++)
    {
        m[a[r]]++;
        if(m[a[r]]==2)
        {
            while(m[a[r]]==2){
                m[a[l]]--;
                l++;
            }
        }
        ans+=r-l+1;
    }
    cout<<ans;
}