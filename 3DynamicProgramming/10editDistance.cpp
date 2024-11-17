#include <bits/stdc++.h>
using namespace std;

#define vec vector

int solve(int ind1, int ind2, string& word1, string& word2, vec<vec<int>> &dp) {
    if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
    else if(ind1 == 0) return dp[ind1][ind2] = ind2;
    else if(ind2 == 0) return dp[ind1][ind2] = ind1;

    if(word1[ind1-1] == word2[ind2-1]) return dp[ind1][ind2] = solve(ind1-1, ind2-1, word1, word2, dp);

    return dp[ind1][ind2] =  1 + min(solve(ind1-1, ind2, word1, word2, dp), min(solve(ind1, ind2-1, word1, word2, dp), solve(ind1-1, ind2-1, word1, word2, dp)));
}

int minDistance(string& word1, string& word2) {
    int n1 = word1.size(), n2 = word2.size();
    vec<vec<int>> dp(n1+1, vector<int>(n2+1, -1));
    return solve(n1, n2, word1, word2, dp);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << minDistance(s1, s2) << endl;
}