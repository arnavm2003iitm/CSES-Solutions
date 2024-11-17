#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define rep(i, s, n) for(int i = s; i < n; i++)
#define um unordered_map 
#define us unordered_set

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

void dfs(int node, int& thisConnected, vec<vec<int>>& adj, vec<bool>& vis) {
    thisConnected++;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            vis[it] = 1;
            dfs(it, thisConnected, adj, vis);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vec<vec<int>> adj(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        addEdge(adj, a-1, b-1);        

        int connected = 0, maxConnected = 0;
        vec<bool> vis(n, 0);
        rep(node, 0, n) {
            int thisConnected = 0;
            if(!vis[node]) {
                connected++;    
                vis[node] = 1;
                dfs(node, thisConnected, adj, vis);
                maxConnected = max(maxConnected, thisConnected);
            }
        }
        cout << connected << ' ' << maxConnected << endl;  
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}