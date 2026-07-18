#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int min_diff = 100000;

int dfs(int u, int p, int n) {
    int s = 1;
    for (int x : graph[u])
        if (x != p)
            s += dfs(x, u, n);
    
    int diff = abs(n - 2*s); // (N - S) - S = N - 2*S
    min_diff = (min_diff > diff) ? diff : min_diff;
    
    return s;
}

int solution(int n, vector<vector<int>> wires) {
    graph.resize(n+1);
    for (auto& e : wires) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dfs(1, 0, n);
    
    int answer = min_diff;
    return answer;
}