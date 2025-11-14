#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void bfs(vector<vector<int>>& farm, int a, int b, vector<vector<int>>& visited) {
    queue<pair<int,int>> q;
    q.push({a, b});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < farm[0].size() && 
            ny >= 0 && ny < farm.size() && 
            farm[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, k;
    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        int cnt = 0;
        vector<vector<int>> farm(n, vector<int>(m));
        vector<vector<int>> visited(n, vector<int>(m));
        while(k--) {
            int x, y;
            cin >> x >> y;
            farm[y][x] = 1;
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (farm[i][j] && !visited[i][j]) {
                    cnt++;
                    bfs(farm, j, i, visited);
                }
            }
        }
        cout << cnt << "\n";
    }
}