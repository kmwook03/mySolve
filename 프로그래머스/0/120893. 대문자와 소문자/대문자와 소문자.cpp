#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string result = "";

    for (const auto c: my_string)
    {
        if (c >= 97) result += (c - 32);
        else result += (c + 32);
    }
    return result;
}