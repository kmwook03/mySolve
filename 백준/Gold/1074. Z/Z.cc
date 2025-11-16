#include <bits/stdc++.h>

using namespace std;

void travel(int width, int r, int c, int& cnt) {
    if (width == 2) {
        cnt += 2*r+c;
        return;
    }

    int divided = width/2;
    if (r >= divided) {
        cnt += (width*divided);
        r -= divided;
        if (c >= divided) {
            cnt += (divided*divided);
            c -= divided;
        }
    } else {
        if (c >= divided) {
            cnt += (divided*divided);
            c -= divided;
        }
    }
    travel(divided, r, c, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    int cnt = 0;
    travel(pow(2, n), r, c, cnt);
    cout << cnt << "\n";
}