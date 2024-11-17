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
vec<ll> dp;
vec<vec<int>> adj;

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

int dfs(int node) {
    if(node == n) return dp[node] = 1;
    if(dp[node] != -1) return dp[node];

    ll cnt = 0;
    for(auto it : adj[node]) {
        cnt = (cnt + dfs(it)) % int(pow(10, 9) + 7);
    }
    
    return dp[node] = cnt;
}

void solve() {
    cin >> n >> m;
    
    dp.resize(n + 1, -1);   
    adj.resize(n + 1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b); 
    }

    cout << dfs(1) << endl;  
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}