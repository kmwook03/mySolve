#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int k;

    cin >> n;
    cin >> k;
    vector<int> lights(n, 1);
    int mostOff = 0;

    while(k--)
    {
        int i;
        cin >> i;
        
        int off = 0;
        int j=1;
        while (i*j <= n)
        {
            lights[i*j-1] = !(lights[i*j-1]);
            j++;
        }

        for (auto l : lights)
        {
            if (!l) off++;
        }
        if (off > mostOff) mostOff = off;
    }

    cout << mostOff << endl;

    return 0;
}