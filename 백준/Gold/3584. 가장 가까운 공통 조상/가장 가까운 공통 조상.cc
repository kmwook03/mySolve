#include <iostream>
#include <vector>
#include <algorithm>

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

        vector<int> ancestor1;
        ancestor1.emplace_back(c1);
        vector<int> ancestor2;
        ancestor2.emplace_back(c2);

        int c1_root = 0;
        int c2_root = 0;


        
        while (!c1_root || !c2_root) {
            if (parents[ancestor1.back()]) ancestor1.emplace_back(parents[ancestor1.back()]);
            else c1_root = 1;
            if (parents[ancestor2.back()]) ancestor2.emplace_back(parents[ancestor2.back()]);
            else c2_root = 1;
        }
        
        if (ancestor1.size() < ancestor2.size()) {
            for (auto a : ancestor2) {
                auto iter = find_if(ancestor1.begin(), ancestor1.end(), [a](auto i){ return a == i; });
                if (iter != ancestor1.end()) {
                    cout << *iter << '\n';
                    break;
                }
            }
        } else {
            for (auto a : ancestor1) {
                auto iter = find_if(ancestor2.begin(), ancestor2.end(), [a](auto i){ return a == i; });
                if (iter != ancestor2.end()) {
                    cout << *iter << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}