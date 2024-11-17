#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define rep(i, s, n) for(int i = s; i < n; i++)
#define um unordered_map 
#define us unordered_set
#define pii pair<int, int>
#define vv(t) vector<vector<t>>
#define pb push_back
#define pf push_front

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

bool recur(int ind, int& n, ll& sum, vec<int>& ds) {
    if(sum == n*(n-1)/4) return true;
    if(ind == n) return false;

    bool notTake = recur(ind + 1, n, ds);
    ds.pb(ind);
    bool take = recur(ind + 1, n, ds);
    ds.pop_back();

    return take || notTake;
}

void solve() {
    ll n;
    cin >> n;
    ll sum = n*(n - 1)/2;

    if(sum % 2) {
        cout << "NO" << endl;
        return;
    }
    sum = sum/2;

    vec<int> ds;
    ll cur = 0;
    recur(0, n, cur, ds);        
}   

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}