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

int n;
vv(ll) adj;
vec<ll> dp1, dp2; 
void addEdge(ll u, ll v) { 
    adj[u].pb(v); 
    adj[v].pb(u); 
}

void dfs(ll node, ll parent) {
    for(auto u : adj[node]) {
        if(u == parent) continue;
        dfs(u, node);
        dp2[node] += max(dp2[u], dp1[u]);
    }

    for(auto u : adj[node]) {
        if(u == parent) continue;
        dp1[node] = max(dp1[node], dp2[u] + 1 + dp2[node] - max(dp2[u], dp1[u]));
    }
}

void solve() {
    cin >> n;
    adj.resize(n);
    
    rep(i, 1, n) {
        ll a, b;
        cin >> a >> b;
        addEdge(a-1, b-1);
    }
    dp1.resize(n, 0);
    dp2.resize(n, 0);
    dfs(0, -1);
    cout << max(dp1[0], dp2[0]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    ll T = 1;
    // cin >> T;
    rep(t, 0, T) solve();

    return 0;
}