#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int bfs(int x, int y, vector<vector<int>>& picture, vector<vector<int>>& visited) {
    queue<pair<int, int>> q;
    q.push({x, y});
    int area = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < picture[0].size() && ny >= 0 && ny < picture.size() && picture[ny][nx] == picture[y][x] && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                area++;
                q.push({nx, ny});
            }
        }
     
    }
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0) visited[i][j] = 1;
            else if (!visited[i][j]) {
                cout << "hi\n";
                int area = bfs(j, i, picture, visited);
                if (area >= max_size_of_one_area) max_size_of_one_area = area;
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}