#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod;
int pow(int a,int b)
{
    if(b == 0) return 1;
    if(b % 2 == 0) return (pow(a,b/2)%mod * pow(a,b/2)%mod)%mod;
    else return (a * pow(a,(b-1)/2)%mod * pow(a,(b-1)/2)%mod)%mod;
}
signed main()
{
    int t;
    cin >> t;
    mod = 1e9 + 7;
    while(t--)
    {
        int  a, b;
        cin >> a >> b;
        cout << pow(a,b) <<"\n";
    }
}