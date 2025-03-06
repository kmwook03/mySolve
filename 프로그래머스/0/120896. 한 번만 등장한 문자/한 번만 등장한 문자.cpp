#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    unordered_map<char, int> count;

    for (const auto c : s) count[c]++;
    
    for(auto it = count.begin(); it !=count.end(); it++)
    {
        if (it->second == 1) answer += it->first;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}