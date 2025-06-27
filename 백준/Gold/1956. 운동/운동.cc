#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int INF = ~0U >> 2;

int CycleFloyd(vector<vector<int>>& cities, int n) {
    vector<int> cycle;
    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            for (auto k=0; k<n; k++) {
                if (cities[j][k] > cities[j][i]+cities[i][k]) cities[j][k] = cities[j][i]+cities[i][k];
            }
        }
    }
    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            if (i!=j) cycle.push_back(cities[i][j] + cities[j][i]);
        }
    }

    return *min_element(cycle.begin(), cycle.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;
    vector<vector<int>> cities(v, vector<int>(v, 0));
    for (auto i=0; i<v; i++) {
        for (auto j=0; j<v; j++) {
            if (i!=j) cities[i][j] = INF;
        }
    }

    for (auto i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (cities[a-1][b-1] > c) cities[a-1][b-1] = c;
    }

    int min_cycle = CycleFloyd(cities, v);

    if (min_cycle == 0 || min_cycle >= INF) cout << -1 << endl;
    else cout << min_cycle << endl;

    return 0;
}