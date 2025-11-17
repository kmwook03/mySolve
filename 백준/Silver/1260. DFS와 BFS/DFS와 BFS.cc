#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& graph, int v, vector<int>& visited) {
    if (visited[v]) return;
    visited[v] = 1;
    cout << v << " ";
    for (int i=0; i<graph[v].size(); i++) {
        dfs(graph, graph[v][i], visited);
    }
}

void bfs(vector<vector<int>>& graph, int v) {
    vector<int> visited(graph.size()); visited[0] = 1;
    queue<vector<int>> q;
    q.push(graph[v]);
    visited[v] = 1;
    cout << v << " ";
    while(!q.empty()) {
        for (auto& i : q.front()) {
            if (!visited[i]) {
                cout << i << " ";
                q.emplace(graph[i]);
                visited[i] = 1;
            }
        }
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n+1);
    while(m--) {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].emplace_back(n2);
        graph[n2].emplace_back(n1);
    }
    for (auto& p : graph) sort(p.begin(), p.end());
    vector<int> visited(graph.size()); visited[0] = 1;

    dfs(graph, v, visited);
    cout << "\n";
    bfs(graph, v);
}