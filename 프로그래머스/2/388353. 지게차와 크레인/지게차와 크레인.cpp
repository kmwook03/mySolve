#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int forklift(char& req, vector<string>& map) {
    int popped = 0;
    int row = map.size(), col = map[0].size();
    
    vector<vector<int>> visited(row, vector<int>(col, 0));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < row && 0 <= ny && ny < col && !visited[nx][ny]) {
                if (map[nx][ny] == '.') {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                } else if (map[nx][ny] == req) {
                    popped++;
                    visited[nx][ny] = 1;
                    map[nx][ny] = '.';
                }
            }
        }
    }
    
    return popped;
}

int crane(char& req, vector<string>& map) {
    int popped = 0;
    int row = map.size(), col = map[0].size();
    for (int i = 1; i < row-1; i++) {
        for (int j = 1; j < col-1; j++) {
            if (map[i][j] == req) {
                popped++;
                map[i][j] = '.';
            }
        }
    }
    return popped;
}

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size(), m = storage[0].size();
    
    // 맵 구성
    string padding(m+2, '.');
    vector<string> map;
    map.push_back(padding);
    for (auto& row: storage) map.push_back("." + row + ".");
    map.push_back(padding);
    
    // 남은 컨테이너 개수
    int containers = n*m;
    for (auto& req: requests) {
        if (req.length() == 1) containers -= forklift(req[0], map);
        else if (req.length() == 2) containers -= crane(req[0], map);
    }
    
    return containers;
}