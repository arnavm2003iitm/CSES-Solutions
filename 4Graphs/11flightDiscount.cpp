#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define rep(i, s, n) for(int i = s; i < n; i++)
#define umm unordered_map 
#define uss unordered_set
#define pqq priority_queue
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vv(t) vector<vector<t>>
#define pb push_back
#define mp make_pair
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

ll n, m;
vv(pll) adj[2];
void addEdge(ll u, ll v, ll w) { 
    adj[0][u].pb(mp(v, w)); 
    adj[1][v].pb(mp(u, w)); 
}

void djik(pqq<pll, vec<pll>, greater<pll>>& pq, vv(ll)& d, int dir) {
    vec<bool> vis(n, false);

    while(!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto it : adj[dir][u]) {
            ll v = it.first, w = it.second;
            d[dir][v] = min(d[dir][v], d[dir][u] + w);
            pq.push({d[dir][v], v});
        }
    }    
}

void solve() {
    cin >> n >> m;

    adj[0].resize(n);
    adj[1].resize(n);
    rep(i, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        addEdge(a-1, b-1, c);
    }   

    pqq<pll, vec<pll>, greater<pll>> pq;    
    vv(ll) d(2, vec<ll>(n, LLONG_MAX));

    d[0][0] = 0;
    d[1][n-1] = 0;

    pq.push({0, 0});
    djik(pq, d, 0);

    pq.push({0, n-1});
    djik(pq, d, 1);

    ll md = LLONG_MAX;
    rep(u, 0, n) {
        for(auto it : adj[0][u]) {
            ll v = it.first, w = it.second; 
            if(d[0][u] == LLONG_MAX || d[1][v] == LLONG_MAX) continue;
            md = min(md, d[0][u] + d[1][v] + w/2);
        }
    }

    cout << md << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}