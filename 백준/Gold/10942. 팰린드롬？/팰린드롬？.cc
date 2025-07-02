#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int64_t n;
    std::cin >> n;

    std::vector<int64_t> num(n+1);
    for (auto i=1; i<=n; i++) std::cin >> num[i];

    std::vector<std::vector<int64_t>> pal_dp(n+1, std::vector<int64_t>(n+1, 0));

    for (auto i=1; i<=n; i++) pal_dp[i][i] = 1;
    for (auto i=1; i<n; i++) if (num[i]==num[i+1]) pal_dp[i][i+1] = 1;

    for (auto len=3; len<=n; len++) {
        for (auto i=1; i<=n-len+1; i++) {
            auto j = i+len-1;
            if (num[i]==num[j] && pal_dp[i+1][j-1]) pal_dp[i][j] = 1;
        }
    }


    int64_t m;
    std::cin >> m;

    while (m--) {
        int64_t begin, end;
        std::cin >> begin >> end;
        std::cout << pal_dp[begin][end] << '\n';
    }

    return 0;
}