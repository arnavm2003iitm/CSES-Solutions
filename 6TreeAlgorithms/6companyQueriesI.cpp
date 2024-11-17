#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec(t) vector<t>
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
    vector<vector<int>> pow2ends;

public:
    Tree(const vector<int> &parents) 
        : log2dist(ceil(log2(parents.size() + 1))), par(parents.size() + 1), pow2ends(par.size(), vector<int>(log2dist+1)) {
            par[0] = -1;
            rep(i, 0, parents.size()) par[i + 1] = parents[i];
    
            rep(n, 0, par.size()) pow2ends[n][0] = par[n];
            rep(p, 1, log2dist+1) {
                rep(n, 0, par.size()) {
                    int half = pow2ends[n][p - 1];
                    if(half == -1) pow2ends[n][p] = -1;
                    else pow2ends[n][p] = pow2ends[half][p - 1];
                }
            }
    }
     
    int kth_parent(int n, int k) {
        int at = n;
        rep(pow, 0, log2dist+1) {
            if((k & (1 << pow)) != 0) {
                at = pow2ends[at][pow];
                if(at == -1) break;
            } 
        }
        return at;
    }

    void getPow2Ends() { cout << pow2ends; }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vec(int) parents(n-1);
    rep(i, 0, n-1) {
        int a;
        cin >> a;
        parents[i] = a-1;
    } 

    Tree tree(parents);
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;

        int ans = tree.kth_parent(a-1, b);
        cout << ((ans == -1) ? -1 : (ans+1)) << endl;
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