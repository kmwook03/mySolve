#include <iostream>
#include <queue>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<int> positions;
    for (auto i = 1; i<= n; i++) positions.push(i);

    std::cout << "<";
    while (positions.size() > 1) {
        for (int i=0; i<k-1; i++) {
            positions.push(positions.front());
            positions.pop();
        }
        std::cout << positions.front() << ", ";
        positions.pop();
    }
    std::cout << positions.front() << ">\n";
}