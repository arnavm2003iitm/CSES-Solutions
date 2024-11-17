#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dfs(int x, int y, vector<string>& grid, vector<vector<ll>>& dp) {
    int n = grid.size();
    if(x < 0 || y < 0 || x == n || y == n || grid[x][y] == '*' || dp[x][y] == 0) return 0;     
    if(dp[x][y] >= 1) return dp[x][y];
    return dp[x][y] = (dfs(x + 1, y, grid, dp) +  dfs(x, y + 1, grid, dp)) % int(pow(10, 9) + 7);
}

void solve() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<ll>> dp(n, vector<ll> (n, -1));
    dp[n-1][n-1] = 1;
    if(grid[n-1][n-1] == '*' || grid[0][0] == '*') cout << 0 << endl;
    else cout << dfs(0, 0, grid, dp) << endl;
}

int main() {
    solve();
}