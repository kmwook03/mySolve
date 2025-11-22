#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& visited, int start, vector<int>& bacon_num) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    bacon_num[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto& next : graph[curr]) {
            if (!visited[next]) {
                bacon_num[next] = bacon_num[curr] + 1;
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<vector<int>> bacon_nums(n, vector<int>(n));
    while(m--) {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1-1].emplace_back(n2-1);
        graph[n2-1].emplace_back(n1-1);
    }
    
    int minIdx = 0;
    int _min = INT_MAX;
    for (int i=0; i<n; i++) {
        vector<int> visited(n);
        bfs(graph, visited, i, bacon_nums[i]);
    }
    vector<pair<int, int>> bacon;
    for (int i=0; i<n; i++) {
        pair<int, int> b_sum = {i, accumulate(bacon_nums[i].begin(), bacon_nums[i].end(), 0)};
        bacon.emplace_back(b_sum);
    }

    pair<int, int> minBacon = *min_element(bacon.begin(), bacon.end(), [](auto& a, auto& b){ return a.second < b.second; });
    cout << minBacon.first+1 << "\n";
}