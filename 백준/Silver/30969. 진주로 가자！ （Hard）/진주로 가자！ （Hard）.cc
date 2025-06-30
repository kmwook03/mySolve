#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> costs(1001, 0);

    long long jinju_cost = -1;
    int cnt = 0;

    while (n--) {
        string arrival;
        long long cost;
        
        cin >> arrival >> cost;

        if (arrival == "jinju") {
            jinju_cost = cost;
            cout << jinju_cost << '\n';
            for (auto c = jinju_cost+1; c<=1000; c++) {
                cnt += costs[c];
            }
        } else {
            if (jinju_cost == -1) {
                if (cost <= 1000) costs[cost]++;
                else cnt++;
            } else {
                if (cost > jinju_cost) cnt++;
            }
        }
    }

    cout << cnt << '\n';
    
    return 0;
}