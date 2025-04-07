#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<int> isSeven = {0, 0, 0};
    for (int i=0; i<3; i++)
    {
        string wheel;
        getline(cin, wheel);
        stringstream ss(wheel);
        int num;
        while (ss>>num)
        {
            if (num==7) isSeven[i] = 1;
        }
    }
    if (find(isSeven.begin(), isSeven.end(), 0) == isSeven.end()) cout << 777 << endl;
    else cout << 0 << endl;
    return 0;
}