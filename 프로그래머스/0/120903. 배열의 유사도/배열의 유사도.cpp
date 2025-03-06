#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for (const auto s : s1)
    {
        for (const auto t : s2)
        {
            if (s==t) answer++;
        }
    }
    return answer;
}