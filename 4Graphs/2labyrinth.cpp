#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid (n, vector<char> (m, ' '));
    int ai = 0, aj = 0, bi = 0, bj = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') ai = i, aj = j;
            if(grid[i][j] == 'B') bi = i, bj = j;
        }
    }

    queue<pair<int, int>> q;
    q.push({ai, aj});
    grid[ai][aj] = '#';

    vector<vector<char>> dirHistory (n, vector<char> (m, ' '));
    vector<char> path;
    bool flag = false;

    string dirs = "URDL";
    vector<int> ni {-1, 0, 1, 0};
    vector<int> nj {0, 1, 0, -1};

    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();

        if(i == bi && j == bj) {
            flag = true;

            while(1) {
                path.push_back(dirHistory[i][j]);
                if(dirHistory[i][j] == 'U') i++;
                else if(dirHistory[i][j] == 'R') j--;
                else if(dirHistory[i][j] == 'D') i--;
                else if(dirHistory[i][j] == 'L') j++;

                if(i == ai && j == aj) break;
            }
        }

        if(flag) break;

    
        for(int k = 0; k < 4; k++) {
            int newi = i + ni[k], newj = j + nj[k];
            if(newi < 0 || newj < 0 || newi == n || newj == m || grid[newi][newj] == '#') continue;
            q.push({newi, newj});
            dirHistory[newi][newj] = dirs[k];
            grid[newi][newj] = '#';
        }
    }

    if(flag == false) cout << "NO";
    else {
        cout << "YES" << endl << path.size() << endl;
        while(!path.empty()) {
            cout << path.back();
            path.pop_back();
        }
    }
}