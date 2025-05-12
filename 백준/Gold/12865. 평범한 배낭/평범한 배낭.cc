#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long n, k;
    cin >> n >> k;
    vector<int> weights;
    vector<int> values;

    while(n--)
    {
        long w, v;
        cin >> w >> v;
        weights.push_back(w);
        values.push_back(v);
    }
    n = weights.size();
    vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
    
    for (int i=1; i<n+1; i++)
    {
        for (int w=1; w<k+1; w++)
        {
            if (weights[i-1]<=w) dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]]+values[i-1]);
            else dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[n][k] << endl;


    return 0;
}