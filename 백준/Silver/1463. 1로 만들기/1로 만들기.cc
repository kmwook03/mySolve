#include <bits/stdc++.h>

using namespace std;

int make_one(long long n) {
    vector<long long> dp(n+1);
    dp[0] = 0;
    dp[1] = 0;
    if (n>1) dp[2] = 1;
    if (n<3) return dp[n];

    for (int i=3; i<=n; i++) {
        int num = i;
        vector<long long> op_result;
        if (num%3 == 0) op_result.emplace_back(num/3);
        if (num%2 == 0) op_result.emplace_back(num/2);
        op_result.emplace_back(num-1);

        if (op_result.size() == 3) dp[i] = min({dp[op_result[0]], dp[op_result[1]], dp[op_result[2]]}) + 1;
        else if (op_result.size() == 2) dp[i] = min({dp[op_result[0]], dp[op_result[1]]}) + 1;
        else dp[i] = dp[op_result[0]] + 1;
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    cout << make_one(n) << "\n";
}