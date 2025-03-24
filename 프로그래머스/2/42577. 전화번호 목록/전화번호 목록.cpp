#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> headCheck;
    
    for (const auto p : phone_book) headCheck[p] = 0;
    
    for (const auto p : phone_book)
    {
        string head="";
        for (auto n : p)
        {
            head += n;
            if ((head != p) && headCheck.find(head) != headCheck.end())
            {
                answer = false;
                break;
            }
        }
        if (!answer) break;
    }
    
    return answer;
}