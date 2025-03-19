#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> p;
    for (int i=0; i<participant.size(); i++) p[participant[i]]++;
    for (int j=0; j<completion.size(); j++) p[completion[j]]--;
    for (auto it = p.begin(); it != p.end(); it++)
    {
        if (it->second != 0) answer += it->first;
    }

    return answer;
}