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
    vector<int> path1, path2;
    queue<int> q;
    bool flag = false;

    for(int i = 0; i < n && !flag; i++) if(!vis[i]) {
        q.push(i);
        vis[i] = true;      

        while(!q.empty() && !flag) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = true;
                    history[it] = node;
                    q.push(it);
                }
                else if(history[node] != it){
                    flag = true;

                    while(node != it) {
                        if(path2.empty() || path2.back() != it) path2.push_back(it);
                        if(path1.empty() || path1.back() != node) path1.push_back(node);
                        node = history[node];
                        it = history[it];
                    }
                    if(path1.empty() || path1.back() != node) path1.push_back(node);
                    if(path2.empty() || path2.back() != it) path2.push_back(it);

                    reverse(path1.begin(), path1.end());
                    for(auto num : path2) path1.push_back(num);
                    
                    break;
                }
            }
        }
    }

    if(flag) {
        cout << path1.size() << endl;
        while(!path1.empty()) cout << (path1.back() + 1) << ' ', path1.pop_back();
    }
    else cout << "IMPOSSIBLE";
}