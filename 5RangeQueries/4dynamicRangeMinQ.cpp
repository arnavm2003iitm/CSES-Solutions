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

template <class T> class MinSegmentTree {
private:
    const T DEFAULT = numeric_limits<T>().max();

    int len;
    vector<T> segtree;

    T combine(const T &a, const T &b) { return min(a, b); }
    
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

    T range_min(int start, int end, int node, int left, int right) {
        if(start > right || end < left) return DEFAULT;
        if(start <= left && end >= right) return segtree[node];

        int mid = (left + right)/2;
        T left_res = range_min(start, end, 2*node, left, mid);
        T right_res = range_min(start, end, 2*node + 1, mid + 1, right);

        return combine(left_res, right_res); 
    }

public:
    MinSegmentTree(const vector<T> &arr) : len(arr.size()) {
        segtree = vector<T>(len*4, DEFAULT);
        build(arr, 1, 0, len - 1);
    }

    void set(int ind, int val) { set(ind, val, 1, 0, len - 1); }
    T range_min(int start, int end) { return range_min(start, end, 1, 0, len - 1);  }
    
    vector<T> getSegTree() { 
        vector<T> ans;
        for(auto it : segtree) {
            if(it == DEFAULT) continue;
            ans.pb(it);
        }
        return ans;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];

    MinSegmentTree<ll> segtree(arr);

    rep(i, 0, q) {
        int type;
        cin >> type;

        if(type == 1) {
            int k, u;
            cin >> k >> u;
            segtree.set(k-1, u);
        }
        else if(type == 2) {
            int a, b;
            cin >> a >> b;
            cout << segtree.range_min(a-1, b-1) << endl;    
        }
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