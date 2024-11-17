#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;

    vec<ll> x(n);
    vec<ll> prefix(n+1, 0);
    fr(i, n) cin >> x[i];
    fr(i, n) prefix[i+1] = prefix[i] + x[i];

    vec<vec<ll>> dp (n, vec<ll> (n, 0));

    for(int l = n - 1; l >= 0; l--) {
        for(int r = l; r < n; r++) {
            if(r == l) dp[l][r] = x[l];
            else {
                ll takeLeft  = x[l] + (prefix[r + 1] - prefix[l + 1] - dp[l + 1][r]);
                ll takeRight = x[r] + (prefix[r] - prefix[l] - dp[l][r - 1]);
                dp[l][r] = max(takeLeft, takeRight);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}

int main() {
    solve();
}