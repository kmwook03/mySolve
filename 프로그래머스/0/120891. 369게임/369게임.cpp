#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int clap = 0;
    int num = 0;
    while (order)
    {
        num = order % 10;
        if (num != 0 && num%3 == 0) clap++;
        order /= 10;
    }
    return clap;
}