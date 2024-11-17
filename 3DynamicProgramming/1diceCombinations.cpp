#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int dice = 1; dice <= 6; dice++) if(i - dice >= 0) dp[i] += dp[i - dice];
        dp[i] = dp[i] % int(pow(10, 9) + 7);
    }
    cout << dp[n] << endl;
}

int main() {
    solve();
}