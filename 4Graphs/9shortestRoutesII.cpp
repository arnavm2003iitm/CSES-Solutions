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

ll n, m, q;
vec<vec<pll>> adj;

void addEdge(ll u, ll v, ll w) { 
    adj[u].pb(mp(v, w));
    adj[v].pb(mp(u, w)); 
}

void solve() {
    cin >> n >> m >> q;

    vec<vec<ll>> d(n, vec<ll> (n, LLONG_MAX));
    rep(i, 0, n) d[i][i] = 0;
    rep(i, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        d[a - 1][b - 1] = min(d[a - 1][b - 1], c);
        d[b - 1][a - 1] = min(d[b - 1][a - 1], c);
    }

    rep(k, 0, n) 
        rep(i, 0, n) 
            rep(j, 0, n) 
                if(d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX) 
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    rep(i, 0, n) 
        rep(j, 0, n) 
            if(d[i][j] >= LLONG_MAX) d[i][j] = -1;

    rep(i, 0, q) {
        ll a, b;
        cin >> a >> b;
        cout << d[a-1][b-1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}