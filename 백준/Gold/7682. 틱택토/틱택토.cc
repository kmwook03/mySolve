#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        string line;
        cin >> line;
        if (line == "end") break;

        int X_cnt = 0; int O_cnt = 0;
        bool X_success = false;
        bool O_success = false;

        for (auto c : line) {
            if (c=='X') X_cnt++;
            else if (c=='O') O_cnt++;
        }

        auto win = [&](char c){
            return (line[0]==c && line[1]==c && line[2]==c) || (line[3]==c && line[4]==c && line[5]==c) || (line[6]==c && line[7]==c && line[8]==c) || (line[0]==c && line[3]==c && line[6]==c) || (line[1]==c && line[4]==c && line[7]==c) || (line[2]==c && line[5]==c && line[8]==c) || (line[0]==c && line[4]==c && line[8]==c) || (line[2]==c && line[4]==c && line[6]==c);
        };

        X_success = win('X');
        O_success = win('O');

        if (O_cnt > X_cnt || X_cnt > O_cnt+1) cout << "invalid\n";
        else if (X_success && O_success) cout << "invalid\n";
        else if (X_success && X_cnt != O_cnt+1) cout << "invalid\n";
        else if (O_success && X_cnt != O_cnt) cout << "invalid\n";
        else if (!X_success && !O_success && X_cnt+O_cnt != 9) cout << "invalid\n";
        else cout << "valid\n";
    }

    return 0;
}