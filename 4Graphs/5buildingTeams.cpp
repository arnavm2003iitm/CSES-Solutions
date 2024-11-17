#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(int node, vector<bool>& vis, vector<bool>& grp, vector<vector<int>>& adj) {
    vis[node] = 1;
    
    for(auto it : adj[node]) {
        if(!vis[it]) {
            grp[it] = !grp[node];
            if(!dfs(it, vis, grp, adj)) return false;
        }
        else if(grp[it] == grp[node]) return false;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u-1, v-1);
    }

    vector<bool> vis(n, 0);
    vector<bool> grp(n, 0);

    bool flag = 1;
    for(int i = 0; i < n; i++) 
        if(vis[i] == 0 && !dfs(i, vis, grp, adj)) {
            flag = 0;
            break;
        }

    if(flag) for(auto it : grp) cout << (it+1) << ' ';
    else cout << "IMPOSSIBLE";
}