#include <string>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& teams, 
         vector<vector<int>>& loss, vector<int>& sales) {
    loss[u][1] = sales[u-1];
    int sum = 0;
    bool existAttend = false;
    int extra = 1e9;
    
    for (int v : teams[u]) {
        dfs(v, teams, loss, sales);
        loss[u][1] += min(loss[v][0], loss[v][1]);
        
        int min_loss = min(loss[v][0], loss[v][1]);
        sum += min_loss;
        
        if (loss[v][1] <= loss[v][0]) {
            existAttend = true;
        } else {
            extra = min(extra, loss[v][1] - loss[v][0]);
        }
    }
    
    if (teams[u].empty()) {
        loss[u][0] = 0;
    } else {
        loss[u][0] = (existAttend) ? sum : sum + extra;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int n = sales.size();
    
    vector<vector<int>> teams(n+1);
    for (auto& l : links) {
        teams[l[0]].push_back(l[1]);
    }
    
    // loss[i][1] = i번 직원이 참석했을 때, 그 서브트리의 최소 손실
    // loss[i][0] = i번 직원이 불참했을 때, 그 서브트리의 최소 손실
    vector<vector<int>> loss(n+1, vector<int>(2));
    
    dfs(1, teams, loss, sales);
    
    return min(loss[1][0], loss[1][1]);
}