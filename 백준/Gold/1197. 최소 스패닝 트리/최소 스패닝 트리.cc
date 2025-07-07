#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>

std::vector<int64_t> root;
std::vector<int64_t> rank;

struct Edge {
    int64_t a, b, w;
};

int64_t Find(int64_t a) {
    if (root[a] == a) return a;
    else return root[a] = Find(root[a]);
}

void Union(int64_t a, int64_t b) {
    int64_t root_a = Find(a);
    int64_t root_b = Find(b);
    if (root_a != root_b) {
        if (rank[root_a] > rank[root_b]) {
            root[root_b] = root_a; 
        } else if (rank[root_a] < rank[root_b]) {
            root[root_a] = root_b; 
        } else {
            root[root_a] = root_b;
            rank[root_b]++;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int64_t v, e;
    std::cin >> v >> e;

    std::vector<Edge> edges(e);
    for (auto i=0; i<e; i++) std::cin >> edges[i].a >> edges[i].b >> edges[i].w;
    std::sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a.w < b.w; });

    root.resize(v+1, 0);
    rank.resize(v+1, 0);
    std::iota(root.begin(), root.end(), 0);

    int64_t total_weight = 0;
    int64_t edges_cnt = 0;

    for (auto& E : edges) {
        if (Find(E.a) != Find(E.b)) {
            Union(E.a, E.b);
            total_weight += E.w;
            edges_cnt++;
            if (edges_cnt == v-1) break;
        }
    }

    std::cout << total_weight << '\n';

    return 0;
}