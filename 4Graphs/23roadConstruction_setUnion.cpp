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
int maxConnected = 0;
vec<int> parent;
vec<int> set_size;

void make_set(int v) {
    parent[v] = v;
    set_size[v] = 1;
}

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        if(set_size[a] < set_size[b]) swap(a, b);
        parent[b] = a;
        set_size[a] += set_size[b]; 
        maxConnected = max(maxConnected, set_size[a]);
        return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;

    parent.resize(n + 1);
    set_size.resize(n + 1);
    rep(i, 1, n + 1) make_set(i);

    int connected = n;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        if (union_sets(a, b)) connected--;
        cout << connected << ' ' << maxConnected << endl;
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}