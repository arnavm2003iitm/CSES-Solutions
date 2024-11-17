#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string& cur, string& ans, vector<vector<char>>& plan) {
    int n = plan.size(), m = plan[0].size();
    if(i < 0 || i == n || j < 0 || j == m || plan[i][j] == '#') return false;
    if(plan[i][j] == 'B') {
        if(ans == "" || cur.size() < ans.size()) ans = cur;
        return true;
    }

    string dirs = "URDL";
    vector<int> ia {-1, 0, 1, 0};
    vector<int> ja {0, 1, 0, -1};

    bool flag = false;
    for(int k = 0; k < 4; k++) {
        cur += dirs[k];
        plan[i][j] = '#';
        if(solve(i + ia[k], j + ja[k], cur, ans, plan)) flag = true;
        plan[i][j] = '.';
        cur.pop_back();
    }   

    if(!flag) plan[i][j] = '#';
    return flag;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> plan (n, vector<char> (m, ' '));
    int Ai = 0, Aj = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) {
            cin >> plan[i][j];
            if(plan[i][j] == 'A') {
                Ai = i;
                Aj = j;
            }
        }

    string ans = "", cur = "";
    if(!solve(Ai, Aj, cur, ans, plan)) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }
}