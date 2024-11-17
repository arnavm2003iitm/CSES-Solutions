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
 
int n, m;
vec<vec<int>> adjF;
vec<vec<int>> adjB;
vec<bool> vis;
 
void addEdge(int u, int v) {
    adjF[u].push_back(v);
    adjB[v].push_back(u);
}
 
void dfsF(int node) {
    for(auto it : adjF[node]) {
        if(!vis[it]) {
            vis[it] = 1;
            dfsF(it);
        }
    }
}
 
void dfsB(int node) {
    for(auto it : adjB[node]) {
        if(!vis[it]) {
            vis[it] = true;
            dfsB(it);
        }
    }
}
 
void solve() {
    cin >> n >> m;
    
    adjF.resize(n + 1);
    adjB.resize(n + 1);
    vis.resize(n + 1, false);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }
 
    dfsF(1);
    rep(i, 2, n + 1) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << 1 << ' ' << i << endl;  
            return;
        }
    }
 
    fill(vis.begin(), vis.end(), false);
 
    dfsB(1);
    rep(i, 2, n + 1) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << i << ' ' << 1 << endl;  
            return;
        }
    } 
 
    cout << "YES" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();
 
    return 0;
}