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

    set<int> sums, sums1;
    sums.insert(0);

    for(int i : x) {
        sums1 = sums;
        for(int j : sums1) sums.insert(i + j);
    }
    
    cout << (sums.size() - 1) << endl;
    for(int i : sums) if(i) cout << i << ' ';
    cout << endl;
}

int main() {
    solve();    
}

