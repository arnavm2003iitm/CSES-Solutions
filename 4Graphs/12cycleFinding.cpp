#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define rep(i, s, n) for(ll i = s; i < n; i++)
#define rrep(i, s, n) for(ll i = n - 1; i >= s; i--)
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

ll n, m;
vv(pll) adj;
vec<bool> vis;
vec<ll> path;
ll target;
void addEdge(ll u, ll v, ll w) { adj[u].pb(mp(v, w)); }

bool dfs(ll node) {
    vis[node] = true;

    if(node == target) return true;

    for(auto it1 : adj[node]) {
        ll it = it1.ff;
        if(!vis[it]) {
            path.pb(it+1);
            if(dfs(it)) return true;
            path.pop_back();
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    bool flag = false;

    adj.resize(n);
    rep(i, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c; 
        addEdge(a-1, b-1, c);
        if(a == b && c < 0) {
            flag = true;
            target = a;
        }
    }
    if(flag) {
        cout << "YES" << endl;
        cout << target << ' ' << target << endl;
        return;
    }

    vec<bool> vis1(n, false);
    
    rep(z, 0, n) {
        if(!vis1[z]) {       
            vec<ll> d(n, LLONG_MAX);
            d[z] = 0;
            vis1[z] = true;

            rep(i, 0, n-1) {
                rep(u, 0, n) {            
                    for(auto it : adj[u]) {
                        ll v = it.ff, w = it.ss;
                        if(d[u] != LLONG_MAX && d[u] + w < d[v]) {
                            d[v] = d[u] + w;
                            vis1[z] = true;
                        }
                    }
                }
            }        

            rep(u, 0, n) {
                for(auto it : adj[u]) {
                    ll v = it.ff, w = it.ss;
                    if(d[u] != LLONG_MAX && d[u] + w < d[v]) {
                        vis.resize(n, false);
                        path.pb(v+1);
                        target = u;
                        dfs(v);
                        path.pb(v+1);
                        cout << "YES" << endl;
                        cout << path << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
}       

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    ll T = 1;
    // cin >> T;
    rep(t, 0, T) solve();

    return 0;
}