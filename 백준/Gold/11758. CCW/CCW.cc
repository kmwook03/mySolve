#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int direction = 0;
    int dx = 0; int dy = 0;
    int px, py;
    vector<vector<int>> dxdy;
    cin >> px >> py;

    for (auto i=0; i<2; i++) {
        int x, y;
        cin >> x >> y;
        dx = x - px;
        dy = y - py;
        dxdy.push_back({dx, dy});
        px = x;
        py = y;
    }

    direction = dxdy[0][0]*dxdy[1][1] - dxdy[0][1]*dxdy[1][0];
    
    if (direction > 0) direction = 1;
    else if (direction < 0) direction = -1;

    cout << direction << endl;
    

    return 0;
}