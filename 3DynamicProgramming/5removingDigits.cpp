#include <bits/stdc++.h>
using namespace std;

#define ll long long

int recur(int x, vector<int>& dp) {
    if(dp[x] != -1) return dp[x];

    int min_steps = INT_MAX;
    string xStr = to_string(x);
    for(int i = 0; i < xStr.length(); i++) {
        int num = x - int(xStr[i]) + 48;
        if(num != x) min_steps = min(min_steps, 1 + recur(num, dp));
    }

    return dp[x] = min_steps;
}

void solve() {
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);
    dp[0] = 0;
    recur(n, dp);
    cout << dp[n] << endl;
}

int main() {
    solve();
}