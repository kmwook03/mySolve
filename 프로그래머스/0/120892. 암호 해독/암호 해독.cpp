#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string result = "";
    for (int i=code-1; i<cipher.length(); i += code)
    {
        result += cipher[i];
    }
    return result;
}