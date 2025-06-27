#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double polygonArea(vector<long> X, vector<long> Y, long Pn) {
    double area = 0;
    long j = Pn-1;

    for (auto i=0; i<Pn; i++) {
        area += (X[j]+X[i])*(Y[j]-Y[i]);
        j = i;
    }

    return abs(area/2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long n;
    cin >> n;
    vector<long> X;
    vector<long> Y;
    for (auto i=0; i<n; i++) {
        long x, y;
        cin >> x >> y;
        X.emplace_back(x);
        Y.emplace_back(y);
    }

    double area = polygonArea(X, Y, n);
    area = round(area*10)/10;

    cout << fixed <<setprecision(1);
    cout << area << endl;

    return 0;
}