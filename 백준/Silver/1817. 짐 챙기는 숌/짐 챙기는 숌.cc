#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double n, m;
    cin >> n >> m;
    vector<int> books;
    if (n>0)
    {
        int book;
        while(n--)
        {
            cin >> book;
            books.push_back(book);
        }
        double bag = 0;
        int cnt = 1;
        for (auto b : books)
        {
            if (bag + b <= m)
            {
                bag += b;
            } else
            {
                cnt++;
                bag = b;
            }
        }
        cout << cnt << endl;
    } else
    {
        cout << 0 << endl;
    }

    return 0;
}