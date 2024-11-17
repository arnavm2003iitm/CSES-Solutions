#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& plan) {
    int n = plan.size(), m = plan[0].size();
    
    if(i < 0 || i == n || j < 0 || j == m || plan[i][j] == '#') return;

    plan[i][j] = '#';

    dfs(i - 1, j    , plan);
    dfs(i    , j + 1, plan);
    dfs(i + 1, j    , plan);
    dfs(i    , j - 1, plan);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> plan (n, vector<char> (m, ' '));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin >> plan[i][j];

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(plan[i][j] == '.') {
                count++;
                dfs(i, j, plan);
            }
        }
    }

    cout << count;
}