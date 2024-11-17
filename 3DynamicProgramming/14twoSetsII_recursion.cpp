#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define fr(i, n) for(int i = 0; i < n; i++)

int n, cnt = 0, k;
void recur(int num, int sum) {
    if(sum == k) {
        cnt = (cnt + 1) % int(pow(10, 9) + 7);
        return;
    }
    if(num > n || sum > k) return;

    recur(num + 1, sum + num); // Take
    recur(num + 1, sum); // Not take
}

void solve() {
    cin >> n;

    int sum = n*(n+1)/2;
    
    if(sum%2 == 0) {
        k = sum/2;
        recur(2, 1);
    }

    cout << cnt << endl;
}

int main() {
    solve();
}