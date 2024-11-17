#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;

    int sum = n*(n+1)/2;
    if(sum%2) {
        cout << 0 << endl;
        return;
    }   
    sum = sum/2;

    vec<ll> dp (sum + 1, 0);
    dp[0] = 1;  

    for(int i = 1; i < n; i++) for(int j = sum; j >= i; j--) dp[j] = (dp[j] + dp[j - i]) % (int(pow(10, 9) + 7));
    cout << dp[sum] << endl;    
}

int main() {
    solve();
}