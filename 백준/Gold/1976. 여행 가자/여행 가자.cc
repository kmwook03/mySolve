#include <iostream>
#include <vector>

std::vector<int> root;
std::vector<int> rank;

int Find(int a)
{
    if (root[a] == a) return a;
    else return root[a] = Find(root[a]);
}

void Union(int a, int b)
{
    int root_a = Find(a);
    int root_b = Find(b);
    if (root_a != root_b)
    {
        if (rank[root_a] > rank[root_b]) root[root_b] = root_a;
        else if (rank[root_a] < rank[root_b]) root[root_a] = root_b;
        else
        {
            root[root_a] = root_b;
            rank[root_b]++;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    root.resize(n+1, 0);
    rank.resize(n+1, 0);

    for (auto i=1; i<n+1; i++) root[i] = i;

    std::vector<std::vector<int>> cities(n, std::vector<int>(n, 0));
    std::vector<int> route(m);
    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            std::cin >> cities[i][j];
            if (cities[i][j]) Union(i+1, j+1);
        }
    }

    for (auto i=0; i<m; i++) std::cin >> route[i];

    bool result = true;

    for (auto r : route) {
        if (Find(route[0]) != Find(r)) {
            result = false;
            break;
        }
    }

    if (result) std::cout << "YES\n";
    else std::cout << "NO\n";

    return 0;
}