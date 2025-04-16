#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    double n;
    cin >> n;
    vector<double> mls;
    while(n--)
    {
        double ml;
        cin >> ml;
        mls.push_back(ml);
    }

    sort(mls.begin(), mls.end());

    double max_drink = mls.back()+(mls[0]/2.0);
    for (int i=1; i<mls.size()-1; i++)
    {
        max_drink += (mls[i]/2);
    }
    cout << max_drink << endl;

    return 0;
}