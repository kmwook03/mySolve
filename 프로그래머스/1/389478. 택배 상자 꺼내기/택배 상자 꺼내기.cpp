#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int w, int num) {
    int cnt = 0;
    
    while (num <= n)
    {
        int floor = ceil((double)num/w);
        cnt++;
        num += 2*(w*floor-num)+1;
    }

    return cnt;
}