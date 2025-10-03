#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<char>>g(m,vector<char>(n));
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>g[i][j];

    // {i,j}
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    if(g[i][j]=='M')
    q.push({i,j});

    int startr,startc;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    if(g[i][j]=='A')
    {
        startr=i;
        startc=j;
        q.push({i,j});
    }

    vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,1,-1};

    vector<vector<char>>moves(m,vector<char>(n,'.'));
    vector<char>dir={'D','U','R','L'};
    bool f=false;
    int endr,endc;
    while(!q.empty())
    {
        auto cur=q.front();
        q.pop();

        int curr=cur.first;
        int curc=cur.second;
        if(g[curr][curc]=='A' && (curr==0 || curr==m-1 || curc==0 || curc==n-1))
        {
            f=true;
            endr=curr;
            endc=curc;
            break;
        }
        for(int i=0;i<4;i++)
        {
            int nr=curr+dr[i];
            int nc=curc+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && g[nr][nc]!='#' && g[nr][nc]!='M')
            {
                if(g[curr][curc]=='M' && g[nr][nc]!='A')
                {
                    g[nr][nc]='M';
                    q.push({nr,nc});
                }
                else if(g[curr][curc]=='A' && g[nr][nc]!='A')
                {
                    g[nr][nc]='A';
                    moves[nr][nc]=dir[i];
                    q.push({nr,nc});
                }
            }
        }
    }

    // for(auto it:moves)
    // {
    //     for(auto it2:it) cout<<it2;
    //     cout<<'\n';
    // }
    // cout<<endr<<" "<<endc<<"\n";
    // cout<<startr<<" "<<startc<<"\n";

    if(!f) cout<<"NO";
    else
    {
        cout<<"YES\n";
        string ans="";
        while(endr!=startr || endc!=startc)
        {
            if(moves[endr][endc]=='U')
            {
                ans+='U';
                endr++;
            }
            else if(moves[endr][endc]=='D')
            {
                ans+='D';
                endr--;
            }
            else if(moves[endr][endc]=='R')
            {
                ans+='R';
                endc--;
            }
            else
            {
                ans+='L';
                endc++;
            }
            // cout<<endr<<" "<<endc<<"\n";
        }
        cout<<ans.size()<<"\n";
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
}