#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n, m;
    cin >> n >> m;

    vec<int> x(n);
    fr(i, n) cin >> x[i];

    vec<int> prev (m, 0);
    vec<int> cur (m, 0);
    vec<int> next (m, 0);

    for(int i = n - 1; i >= 0; i--) {
        if(x[i] != 0 && i == n - 1) cur[x[i] - 1] = 1;
        else if(x[i] == 0 && i == n - 1) for(int j = 0; j < m; j++) cur[j] = 1; 
        else if(x[i] != 0) {
            for(int j = max(1, x[i] - 1); j <= min(m, x[i] + 1); j++) {
                cur[x[i] - 1] = (cur[x[i] - 1] + prev[j - 1]) % int(pow(10, 9) + 7); 
            }
        }
        else if(x[i] == 0) {
            for(int j = 1; j <= m; j++) {
                for(int k = max(1, j - 1); k <= min(m, j + 1); k++) {
                    cur[j - 1] = (cur[j - 1] + prev[k - 1]) % int(pow(10, 9) + 7);
                }
            }
        }

        prev = cur;
        cur = next;
    }

    int ans = 0;
    fr(i, m) ans = (ans + prev[i]) % int(pow(10, 9) + 7);

    cout << ans << endl;
}

int main() {
    solve();
}