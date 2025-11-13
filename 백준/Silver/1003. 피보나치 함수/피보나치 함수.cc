#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> fibo_dp(41, vector<int>(2));
    fibo_dp[0][0] = 1; fibo_dp[0][1] = 0;
    fibo_dp[1][0] = 0; fibo_dp[1][1] = 1;
    
    for (int i=2; i<=40; i++) {
        fibo_dp[i][0] = fibo_dp[i-1][0] + fibo_dp[i-2][0];
        fibo_dp[i][1] = fibo_dp[i-1][1] + fibo_dp[i-2][1];
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << fibo_dp[n][0] << " " << fibo_dp[n][1] << "\n";
    }
}