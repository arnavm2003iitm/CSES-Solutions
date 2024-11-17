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

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve() {
    int n, x;
    cin >> n >> x;

    vec<int> p(n);
    fr(i, n) cin >> p[i];

    sort(p.begin(), p.end());
    int j = lower_bound(p.begin(), p.end(), x/2) - p.begin();
    int i = j - 1, cnt = 0;
    
    cout << p << endl;
    while(i >= 0 && j < n) {
        cout << i << ' ' << j << endl;
        if(p[i] + p[j] <= x) i--, j++;
        else i--;
        cnt++;
    }
    if(i >= 0) cnt += i/2 + 1;
    if(j < n) cnt += n - j;

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}