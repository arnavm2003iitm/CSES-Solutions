#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void solve() {
    int a, b;
    cin >> a >> b;

    vec<vec<int>> dp (a + 1, vec<int> (b + 1, INT_MAX));

    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++) {
            if(i == j) dp[i][j] = 0;
            else {
                for(int hor = 1; hor < i; hor++) dp[i][j] = min(dp[i][j], 1 + dp[hor][j] + dp[i-hor][j]);
                for(int ver = 1; ver < j; ver++) dp[i][j] = min(dp[i][j], 1 + dp[i][ver] + dp[i][j-ver]);
            }            
        }
    cout << dp[a][b] << endl;
}

int main() {
    solve();
}