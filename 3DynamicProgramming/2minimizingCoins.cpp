#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp (x + 1, x + 1);
    dp[0] = 0;

    for(int coin : coins) {
        for(int i = 1; i <= x; i++) {
            if(i >= coin) dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }

    if(dp[x] > x) cout << -1 << endl;
    else cout << dp[x] << endl;
}

int main() {
    solve();
}