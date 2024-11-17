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

    vec<int> temp;
    int len = 1;

    temp.push_back(x[0]);

    for(int i = 1; i < n; i++) {
        for(auto num : temp) cout << num << ' ';
        cout << endl;

        if(x[i] > temp.back()) {
            temp.push_back(x[i]);
            len++;
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), x[i]) - temp.begin();
            temp[ind] = x[i];
        }
    }

    cout << len << endl;
}

int main() {
    solve();
}