#include <iostream>
#include <vector>

using namespace std;

const int INF = ~0U >> 2;

void Floyd(vector<vector<int>>& cities, int n) {
    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            for (auto k=0; k<n; k++) {
                if (cities[j][k] > cities[j][i]+cities[i][k]) cities[j][k] = cities[j][i]+cities[i][k];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long m;

    cin >> n >> m;

    vector<vector<int>> cities(n, vector<int>(n, 0));
    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            if (i!=j) cities[i][j] = INF;
        }
    }

    for (auto i=0; i<m; i++) {
        int departure, arrival, cost;
        cin >> departure >> arrival >> cost;
        if (cities[departure-1][arrival-1] > cost) cities[departure-1][arrival-1] = cost;
    }

    Floyd(cities, n);

    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            if (cities[i][j]==INF) cities[i][j] = 0;
        }
    }
    
    for (auto r : cities) {
        for (auto i : r) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}