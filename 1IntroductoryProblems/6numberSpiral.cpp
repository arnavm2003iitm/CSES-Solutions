#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define rep(i, s, n) for(int i = s; i < n; i++)
#define um unordered_map 
#define us unordered_set
#define pii pair<int, int>
#define vv(t) vector<vector<t>>
#define pb push_back
#define pf push_front

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto element : vector) os << element << " ";
    return os;
}

template <typename S>
ostream& operator<<(ostream& os, const vector<vector<S>>& vector)
{
    for (auto subVector : vector) {
        for(auto element : subVector) os << element << " ";
        os << endl;
    }
    return os;
}

void solve() {
    ll y, x;
    cin >> y >> x;

    ll ans = 0;
    if(y >= x) {
        if(y%2 == 0) ans =  (y - 1)*(y - 1) + (y - x) + y;
        else ans = (y - 1)*(y - 1) + x;
    }
    else {
        if(x%2 == 0) ans = (x - 1)*(x - 1) + y;
        else ans = (x - 1)*(x - 1) + (x - y) + x;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int T;
    cin >> T;
    rep(i, 0, T) solve();

    return 0;
}