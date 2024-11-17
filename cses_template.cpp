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

vv(pll) adj;
void addEdge(ll u, ll v, ll w) { 
    adj[u].pb(mp(v, w));
    adj[v].pb(mp(u, w)); 
}

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    ll T = 1;
    // cin >> T;
    rep(t, 0, T) solve();

    return 0;
}