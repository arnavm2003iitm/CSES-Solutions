#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

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
    int n, q;
    cin >> n >> q;

    vec<ll> minSum(n+1, 0);
    fr(i, n) {
        cin >> minSum[i+1];
        minSum[i+1] = min(minSum[i+1], minSum[i+1] + minSum[i]);
    }

    fr(i, q) {
        int a, b;
        cin >> a >> b;
        cout << minSum[b] - minSum[a - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}