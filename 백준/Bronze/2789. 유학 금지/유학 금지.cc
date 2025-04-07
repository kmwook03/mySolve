#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    string forbided = "CAMBRIDGE";
    string Email;
    unordered_map<char, int> check_map;
    for (auto &c : forbided)
    {
        check_map[c] = 1;
    }
    getline(cin, Email);
    string censored = "";
    for (auto &c : Email)
    {
        if (check_map[c] == 1) continue;
        else censored += c;
    }
    cout << censored << endl;
    return 0;
}