#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int closest = 0;
    int diff = 100;

    for (const auto i: array)
    {
        int nowDiff = abs(i - n);
        if (nowDiff < diff)
        {
            diff = nowDiff;
            closest = i;
        } else if (nowDiff == diff)
        {
            if (closest > i)
            {
                closest = i;
            }
        }
    }
    
    return closest;
}