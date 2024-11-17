#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    
    long long a1 = 1, a2;
    long long b1 = 1, b2;
 
    for(int i = 1; i < n; i++) {
        a2 = (2*a1 + b1) % int(pow(10, 9) + 7);
        b2 = (4*b1 + a1) % int(pow(10, 9) + 7);
        a1 = a2;
        b1 = b2;
    }
 
    long long ans = (a1 + b1) % int(pow(10, 9) + 7);
    cout << ans << endl;
}
 
int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) solve();
}