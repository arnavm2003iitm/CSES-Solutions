#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define rep(i, s, n) for(int i = s; i < n; i++)
#define umm unordered_map 
#define uss unordered_set
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vv(t) vector<vector<t>>
#define pb push_back
#define mp make_pair
#define pqq priority_queue

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

bool dfs(int node, vv(ll)& adj, vec<bool>& vis, uss<ll>& change) {
    if(change.find(node) != change.end()) return false;
    if(vis[node]) return true;
    vis[node] = true;
            
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(!dfs(it, adj, vis, change)) return false;
        }
    }    
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vv(ll) edges;
    vv(ll) adj(n);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb({a-1, b-1, c});
        adj[b-1].pb(a-1);
    }

    vec<ll> d(n, LLONG_MIN);
    d[0] = 0;

    rep(i, 0, n-1) {
        for(auto it : edges) {
            ll u = it[0], v = it[1], w = it[2];
            if(d[u] != LLONG_MIN) d[v] = max(d[v], d[u] + w);
        }
    }

    uss<ll> change;
    for(auto it : edges) {
        ll u = it[0], v = it[1], w = it[2];
        if(d[u] != LLONG_MIN && d[v] < d[u] + w) {
            change.insert(v);
            d[v] = d[u] + w;
        }        
    }

    vec<bool> vis(n, false);
    if(!dfs(n-1, adj, vis, change)) {
        cout << -1 << endl;
        return;
    }

    cout << d[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}