#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;
vector<int> graph[MAX];
vector<int> childs[MAX];

void makeTree(int currentNode, int parent) {
    for (auto node : graph[currentNode]) {
        if (node != parent) {
            childs[currentNode].emplace_back(node);
            makeTree(node, currentNode);
        }
    }
}

void countSubtreeNodes(int currentNode, vector<int>& size) {
    size[currentNode] = 1;
    for (auto node : childs[currentNode]) {
        countSubtreeNodes(node, size);
        size[currentNode] += size[node];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;
    
    for (auto i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> size(n+1);
    makeTree(r, -1);
    countSubtreeNodes(r, size);

    for (auto i=0; i<q; i++) {
        int root;
        cin >> root;
        cout << size[root] << "\n";
    }

    return 0;
}