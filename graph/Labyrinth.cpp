#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int row, col;
    cin >> row >> col;
    vector<string> buildingMap(row);
    pair<int, int> start, end;
    for (int i = 0; i < row; i++) {
        cin >> buildingMap[i];
        for (int j = 0; j < col; j++) {
            if (buildingMap[i][j] == 'A') {
                start = {i, j};
            } else if (buildingMap[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<char>> parent_move(row, vector<char>(col, 0));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    string moves = "DURL";
    bool found = false;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        if (curr == end) {
            found = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = curr.first + dx[i];
            int nc = curr.second + dy[i];
            if (nr >= 0 && nr < row && nc >= 0 && nc < col && buildingMap[nr][nc] != '#' && parent_move[nr][nc] == 0) {
                parent_move[nr][nc] = moves[i]; 
                q.push({nr, nc});
            }
        }
    }

    if (found) {
        cout << "YES\n";
        string path = "";
        pair<int, int> curr = end;
        while (curr != start) {
            char move = parent_move[curr.first][curr.second];
            path += move;
            if (move == 'D') curr.first--;
            else if (move == 'U') curr.first++;
            else if (move == 'R') curr.second--;
            else if (move == 'L') curr.second++;
        }
        reverse(path.begin(), path.end()); 
        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
}