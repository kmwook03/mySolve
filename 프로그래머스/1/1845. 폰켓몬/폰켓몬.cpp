#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int num = 0;
    unordered_map<int, int> pkms;
    for (const auto p : nums) pkms[p]++;
    for (auto it = pkms.begin(); it != pkms.end(); it++)
    {
        if (pkms[it->first] != 0)
        {
            num++;
            pkms[it->first]--;
        }
        if (num >= nums.size()/2) break;
    }
    return num;
}