#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    int target_p = k-1;
    int step = 0;
    std::vector<int> positions(n);

    std::cout << "<";
    for (auto i=0; i<n-1; i++) {
        std::cout << target_p+1 << ", ";
        positions[target_p]++;
        while (step < k) {
            target_p++;
            target_p %= n;
            if (!positions[target_p]) step++;
        }
        step = 0;
    }
    std::cout << target_p+1 << ">\n";
}