#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;
    vec<pair<int, pair<int, int>>> jobs(n); // (End, (Start, Value)) 

    int maxVal = INT_MIN;
    fr(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        jobs[i] = {y, {x, z}};
        maxVal = max(maxVal, jobs[i].first);
    }

    for(auto job : jobs) cout << job.first << ' ' << job.second.first << ' ' << job.second.second << endl;

    vec<vec<int>> dp (maxVal + 1, vec<int> (maxVal + 1, 0));
    for(int i = maxVal; i >= 1; i--) {
        for(int j = i; j >= 1; j--) {
            dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            for(auto job : jobs) {
                if(job.first == j && job.second.first == i) dp[i][j] = max(dp[i][j], job.second.second);
                else if(job.first == j && job.second.first > i) dp[i][j] = max(dp[i][j], job.second.second + dp[i][job.second.first - 1]);
            }
        }
    }


    for(int i = 0; i <= maxVal; i++) {
        for(int j = 0; j <= maxVal; j++) cout << dp[i][j] << ' ';
        cout << endl;
    }

    cout << dp[1][maxVal] << endl;
}

int main() {
    solve();
}