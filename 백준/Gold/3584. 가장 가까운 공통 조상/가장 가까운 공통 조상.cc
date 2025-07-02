#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> parents(n+1);
        for (auto i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            parents[b] = a;
        }

        int c1, c2;
        cin >> c1 >> c2;

        unordered_set<int> visited;

        while (c1) {
            visited.insert(c1);
            c1 = parents[c1];
        }

        while (c2) {
            if (visited.count(c2)) {
                cout << c2 << '\n';
                break;
            } else c2 = parents[c2];
        }
    }
    return 0;
}