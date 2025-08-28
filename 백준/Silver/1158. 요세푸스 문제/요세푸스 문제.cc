#include <iostream>
#include <queue>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<int> positions;
    for (auto i = 1; i<= n; i++) positions.push(i);
    int step = 1;

    std::cout << "<";
    while (positions.size() != 1) {
        if (step == k) {
            std::cout << positions.front() << ", ";
            positions.pop();
            step = 0;
        }
        else {
            positions.push(positions.front());
            positions.pop();
        }
        step++;
    }
    std::cout << positions.front() << ">\n";
}