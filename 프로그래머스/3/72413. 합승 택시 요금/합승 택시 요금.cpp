#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Edge { int to, cost; };

vector<vector<Edge>> buildGraph(int n, vector<vector<int>>& fares) {
    vector<vector<Edge>> graph(n+1);
    for (const auto& f : fares) {
        int u = f[0], v = f[1], c = f[2];
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    
    return graph;
}

vector<int> dijkstra(int n, int s, vector<vector<Edge>>& graph) {
    vector<int> dist(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        
        if (dist[current_node] < current_dist) continue;
        
        for (const auto& e : graph[current_node]) {
            int next_node = e.to;
            int next_dist = current_dist + e.cost;
            
            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    vector<vector<Edge>> graph = buildGraph(n, fares);
    vector<int> dist_s = dijkstra(n, s, graph);
    vector<int> dist_a = dijkstra(n, a, graph);
    vector<int> dist_b = dijkstra(n, b, graph);
    
    for (int i = 1; i <= n; i++) {
        if (dist_s[i] != 1e9 && dist_a[i] != 1e9 && dist_b[i] != 1e9) {
            int cost = dist_s[i] + dist_a[i] + dist_b[i];    
            answer = (answer > cost) ? cost : answer;
        }
    }
    
    return answer;
}