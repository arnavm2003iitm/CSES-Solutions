#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void printVector1D(vector<int>& a) {
    for(auto it : a) cout << it << ' ';
    cout << endl;
}


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vec<int> a(n);
    fr(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    vec<int> b(m);
    fr(i, m) cin >> b[i];
    sort(b.begin(), b.end());

    int cnt = 0, i = 0, j = 0;
    while(i < n && j < m) {
        if(abs(a[i] - b[j]) <= k) {
            i++;
            j++;
            cnt++;
        }
        else if(a[i] > b[j] + k) j++;
        else i++;
    }

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();

    return 0;
}