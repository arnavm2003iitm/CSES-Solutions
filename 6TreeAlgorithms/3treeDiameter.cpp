#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define rep(i, s, n) for(int i = s; i < n; i++)
#define rrep(i, s, n) for(int i = n - 1; i >= s; i--)
#define umm unordered_map 
#define uss unordered_set
#define pqq priority_queue
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vv(t) vector<vector<t>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vmin(a) *min_element(a.begin(), a.end())
#define vmax(a) *max_element(a.begin(), a.end())

template <typename S>
ostream& o  perator<<(ostream& os, const vector<S>& vector)
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

ll n, diameter = 0;
vv(ll) adj;
void addEdge(ll u, ll v, ll w) { adj[u].pb(v)); }

ll dfs(ll node) {
    ll depth = 0;

    ll m1 = 0, m2 = 0;
    for(auto it : adj[node]) {
        ll cur = dfs(it);
        depth = max(depth, cur);
        
    }

    diameter = max(diameter, m1 + m2);

    return depth;
}

void solve() {
    cin >> n;

    adj.resize(n);
    rep(i, 0, n-1) {
        ll a, b;
        cin >> a >> b;
        addEdge(a-1, b-1);
    }

    dfs(0);
    cout << diameter << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    ll T = 1;
    // cin >> T;
    rep(t, 0, T) solve();

    return 0;
}