#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;

    set<int> x;
    fr(i, n) {
        int u;
        cin >> u;
        x.insert(u);
    }

    cout << x.size() << endl;

    // sort(x.begin(), x.end());

    // int cnt = 0, j = 0;
    // while(j < n) {
    //     cnt++;
    //     while(j < n && x[j] == x[j + 1]) j++;
    //     j++;
    // }

    // cout << cnt << endl;
}

int main() {
    solve();
}