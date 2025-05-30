#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
    
void bfs(int a, int b, vector<vector<int>>& land, vector<int>& line)
{
    auto cnt = 0;
    land[a][b]++;
    queue<vector<int>> que;
    que.push({a, b});
    auto min_y = b;
    auto max_y = b;
    while(!que.empty())
    {
        auto x = que.front()[0];
        auto y = que.front()[1];
        que.pop();
        max_y = max(y, max_y);
        min_y = min(y, min_y);
        cnt++;
        for (auto i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < land.size() && ny >= 0 && ny < line.size()-1 && land[nx][ny] == 1)
            {
                ++land[nx][ny];
                que.push({nx, ny});
            }
        }
    }
    for (auto i = min_y; i<max_y+1; i++)
    {
        line[i] += cnt;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<int> line(land[0].size()+1, 0);
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    for (auto i=0; i<land.size(); i++)
    {
        for (auto j=0; j<line.size()-1; j++)
        {
            if (land[i][j] == 1) bfs(i, j, land, line);
        }
    }
    for (auto i : line) cout << i << " ";
    cout << endl;
    answer = *max_element(line.begin(), line.end());
    return answer;
}