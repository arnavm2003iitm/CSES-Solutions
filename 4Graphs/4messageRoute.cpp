#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
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

    vector<bool> vis(n, false);
    vector<int> history(n);
    vector<int> path;
    queue<int> q;
    bool flag = false;

    q.push(0);
    vis[0] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(node == n - 1) {
            flag = true;

            while(1) {
                path.push_back(node);
                node = history[node];
                if(node == 0) break; 
            }
        }

        if(flag) break;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = true;
                q.push(it);
                history[it] = node;
            }
        }
    }

    path.push_back(0);
    if(flag) {
        cout << path.size() << endl;
        while(!path.empty()) cout << (path.back()+1) << ' ', path.pop_back();
    }
    else cout << "IMPOSSIBLE";
}