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

class Tree {
private:
    const int log2dist;
    vector<int> par;
    vector<int> depth;
    vector<vector<int>> pow2ends;
    const vector<vector<int>> &adj;
    
    void dfs(int node, int parent, int level) {
        depth[node] = level;
        par[node] = parent;

        for(auto it : adj[node]) {
            if(it == parent) continue;
            dfs(it, node, level + 1);
        }
    }

public:
    Tree(const vector<vector<int>> &adj) 
    :log2dist(ceil(log2(adj.size()))), par(adj.size()), pow2ends(par.size(), vector<int>(log2dist+1)), depth(adj.size()), adj(adj) {    
        dfs(0, -1, 1);

        rep(node, 0, par.size()) pow2ends[node][0] = par[node];
        rep(pow, 1, log2dist+1) {
            rep(node, 0, par.size()) {
                int half = pow2ends[node][pow - 1];
                if(half == -1) pow2ends[node][pow] = -1;
                else pow2ends[node][pow] = pow2ends[half][pow - 1];
            }
        }
    }

    int kth_element(int node, int k) {
        int at = node;
        rep(pow, 0, log2dist + 1) {
            if((k & (1 << pow)) != 0) {
                at = pow2ends[at][pow];
                if(at == -1) break;
            }
        }
        return at;
    }

    int lca(int a, int b) {
        if(depth[a] > depth[b]) return lca(b, a);

        int d = depth[b] - depth[a];
        b = kth_element(b, depth[b] - depth[a]);

        
        if(a == b) return d;

        rrep(i, 0, log2dist+1) {
            if(pow2ends[a][i] != pow2ends[b][i]) {
                a = pow2ends[a][i];
                b = pow2ends[b][i];
                d += 2*pow(2, i);
            }
        }
        
        d += 2;
        return d;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n);
    rep(i, 1, n) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    Tree tree(adj);

    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << tree.lca(a, b) << endl;   
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    ll T = 1;
    // cin >> T;
    rep(t, 0, T) solve();

    return 0;
}