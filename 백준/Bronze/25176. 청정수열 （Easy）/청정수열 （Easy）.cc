#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = 1;
    while (n>=1)
    {
        result *= n;
        n--;
    }

    cout << result << endl;

    return 0;
}