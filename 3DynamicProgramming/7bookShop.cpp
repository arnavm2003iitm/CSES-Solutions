    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define vec vector
    #define fr(i, n) for(int i = 0; i < n; i++)

    void solve() {
        int n, x;
        cin >> n >> x;

        vec<int> v(n), w(n);
        fr(i, n) cin >> w[i]; // Price
        fr(i, n) cin >> v[i]; // Pages

        vec<int> prev(x+1, 0);
        vec<int> next(x+1, 0);
        for(int i = w[0]; i <= x; i++) prev[i] = v[0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= x; j++) {
                int notTaken = prev[j];
                int taken = INT_MIN;
                if(j >= w[i]) taken = v[i] + prev[j - w[i]];
                next[j] = max(taken, notTaken);
            }
            prev = next;
        }

        cout << prev[x] << endl;
    }

    int main() {
        solve();
    }