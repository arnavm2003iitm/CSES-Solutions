#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp (x + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= x; i++) {
        for(int coin : coins) {
            if(i >= coin) dp[i] = (dp[i] + dp[i - coin]) % int(pow(10, 9) + 7);
        }
    }

    cout << dp[x] << endl;
}

int main() {
    solve();
}