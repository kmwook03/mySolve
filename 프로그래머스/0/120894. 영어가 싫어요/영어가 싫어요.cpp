#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(string numbers) {
    unordered_map<string, int> EtoN;
    EtoN = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, 
            {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, 
            {"eight", 8}, {"nine", 9}};
    
    long long answer = 0;
    string StoN = "";
    
    for (const auto c: numbers)
    {
        StoN += c;
        if (EtoN.find(StoN) != EtoN.end())
        {
            answer = answer*10 + EtoN[StoN];
            StoN = "";
        }
    }
    
    return answer;
}