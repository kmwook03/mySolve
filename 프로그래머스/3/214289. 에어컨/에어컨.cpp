#include <string>
#include <vector>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 1e9;
    int n = onboard.size();
    vector<vector<int>> dp(n+1, vector<int>(51));
    temperature += 10; t1 += 10; t2 += 10;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 51; j++) dp[i][j] = 1e9;
    dp[0][temperature] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 51; j++) {
            if (dp[i][j] == 1e9) continue;
            // 1. 에어컨 off
            int next_temp = j;
            if (temperature < j) next_temp -= 1;
            else if (temperature > j) next_temp += 1;
            dp[i+1][next_temp] = min(dp[i+1][next_temp], dp[i][j]);
            // 2. 에어컨 on / 온도 유지 (비용 b)
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b);
            // 3. 에어컨 on / 온도 변경 (비용 a)
            if (j - 1 >= 0) dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + a);
            if (j + 1 <= 50) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + a);
        }
        if (onboard[i+1] == 1) {
            for (int j = 0; j < 51; j++)
                if (j < t1 || j > t2) dp[i+1][j] = 1e9;
        }
    }
    
    for (int j = 0; j < 51; j++)
        answer = min(answer, dp[n-1][j]);
    
    return answer;
}