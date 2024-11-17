
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;

    vec<int> x(n);
    fr(i, n) cin >> x[i];

    vec<int> dp(n, 1);
    int maxLen = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(x[i] > x[j]) dp[i] = max(dp[i], 1 + dp[j]); 
        }
        maxLen = max(maxLen, dp[i]);
    }    

    cout << maxLen << endl;
}

int main() {
    solve();
}