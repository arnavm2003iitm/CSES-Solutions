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

ll n, m;
vec<vec<pll>> adj;
void addEdge(ll u, ll v, ll w) { adj[u].pb(mp(v, w)); }

void solve() {
    cin >> n >> m;

    pqq<pll, vec<pll>, greater<pll>> pq;
    adj.resize(n);
    rep(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        addEdge(u-1, v-1, w);
    }
    pq.push({0, 0});

    vec<ll> dist(n, LLONG_MAX);
    vec<bool> vis(n, false);
    dist[0] = 0;

    while(!pq.empty()) {
        auto a = pq.top();
        pq.pop();
        ll node = a.second;

        if(vis[node]) continue;
        vis[node] = true;

        for(auto it : adj[node]) {
            if(dist[node] + it.second < dist[it.first]) {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    cout << dist << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}