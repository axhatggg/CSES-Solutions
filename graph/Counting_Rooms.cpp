#include<bits/stdc++.h>
using namespace std;

vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,1,-1};
void dfs(vector<vector<char>> &buildingMap, int row, int col, int i, int j)
{
    buildingMap[i][j]='#';
    for(int x=0;x<4;x++)
    {
        int nr=i+dx[x];
        int nc=j+dy[x];
        if(nr<row && nc<col && nr>=0 && nc>=0 && buildingMap[nr][nc]=='.') 
        dfs(buildingMap,row,col,nr,nc);
    }
}
int main()
{
    int row,col;
    cin>>row>>col;
    vector<vector<char>>buildingMap(row,vector<char>(col));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin>>buildingMap[i][j];
        }
    }
    int ans=0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(buildingMap[i][j]=='.')
            {
                // cout<<i<<" "<<j<<"\n";
                ans++;
                dfs(buildingMap,row,col,i,j);
            }
        }
    }
    cout<<ans;
}