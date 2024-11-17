#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
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

    vector<int> vis(n, 0);
    vector<pair<int, int>> newPairs;
    int count = 0, prev = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            if(prev != -1) {
                count++;
                newPairs.push_back(make_pair(prev+1, i+1));
            }
            prev = i;
        }
    }

    cout << count << endl;
    for(auto it : newPairs) cout << it.first << ' ' << it.second << endl;
}