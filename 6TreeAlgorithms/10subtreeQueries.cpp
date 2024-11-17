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

template <class T> class SumSegmentTree {
private:
    const T DEFAULT = numeric_limits<T>().max();

    int len;
    vector<T> segtree;

    T combine(const T &a, const T &b) { return a+b; }
    
    void build(const vector<T> &arr, int node, int left, int right) {
        if(left == right) {
            segtree[node] = arr[left];
            return;
        }

        int mid = (left + right)/2;
        build(arr, 2*node, left, mid);
        build(arr, 2*node + 1, mid + 1, right);
        segtree[node] = combine(segtree[2*node], segtree[2*node + 1]);
    }

    void set(int ind, T val, int node, int left, int right) {
        if(left == right) {
            segtree[node] = val;
            return;
        }

        int mid = (left + right)/2;
        if(ind <= mid) set(ind, val, 2*node, left, mid);
        else set(ind, val, 2*node + 1, mid + 1, right);

        segtree[node] = combine(segtree[2*node], segtree[2*node + 1]);           
    }

    T range_sum(int start, int end, int node, int left, int right) {
        if(start > right || end < left) return 0;
        if(start <= left && end >= right) return segtree[node];

        int mid = (left + right)/2;
        T left_res = range_sum(start, end, 2*node, left, mid);
        T right_res = range_sum(start, end, 2*node + 1, mid + 1, right);

        return combine(left_res, right_res); 
    }

public:
    SumSegmentTree(const vector<T> &arr) : len(arr.size()) {
        segtree = vector<T>(len*4, 0);
        build(arr, 1, 0, len - 1);
    }

    void set(int ind, int val) { set(ind, val, 1, 0, len - 1); }
    T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1);  }
    
    vector<T> getSegTree() { 
        vector<T> ans;
        for(auto it : segtree) {
            if(it == DEFAULT) continue;
            ans.pb(it);
        }
        return ans;
    }
};

vv(int) adj;
vec<int> start1;
vec<int> end1;
vec<int> preorder;
int timer = 0;

void euler_tour(int node, int parent) {
    start1[node] = timer++;
    preorder.pb(node);
    for(auto it : adj[node]) {
        if(it == parent) continue;
        euler_tour(it, node);
    }
    end1[node] = timer;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> vals(n);
    rep(i, 0, n) cin >> vals[i];

    adj.resize(n);
    rep(i, 1, n) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }   

    start1.resize(n);
    end1.resize(n);
    euler_tour(0, -1);
    
    vector<ll> vals_re;
    for(auto it : preorder) vals_re.pb(vals[it]);
    
    SumSegmentTree<ll> segtree(vals_re);
    rep(i, 0, q) {
        int type, s, x;
        cin >> type >> s;
        s--;
        rep(i, 0, n) {
            if(s == preorder[i]) {
                s=i;
                break;
            }
        }

        if(type == 1) {
            cin >> x;
            segtree.set(s, x);
        }
        else cout << segtree.range_sum(start1[s], end1[s]-1) << endl;
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