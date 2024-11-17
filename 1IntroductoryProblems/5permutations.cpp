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

void solve() {
    int n;
    cin >> n;
    
    if(n <= 3 && n >= 2) {
        cout << "NO SOLUTION" << endl;
        return;
    }     

    for(int i = 2; i <= n; i += 2) cout << i << ' ';
    for(int i = 1; i <= n; i += 2) cout << i << ' ';
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

    return 0;
}