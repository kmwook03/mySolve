#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> root;
vector<int> rAnk;

int find(int a)
{
    if (root[a] == a) return a;
    else return root[a] = find(root[a]);
}

void myUnion(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    if (ra != rb)
    {
        if (rAnk[ra] > rAnk[rb]) root[rb] = ra;
        else if (rAnk[ra] < rAnk[rb]) root[ra] = rb;
        else
        {
            root[ra] = rb;
            rAnk[rb]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    root.resize(n+1, 0);
    rAnk.resize(n+1, 0);

    for (auto i = 1; i<n+1; i++) root[i] = i;
    
    for (auto j=0; j<m; j++)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd)
        {
            if (find(a) == find(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        } else
        {
            myUnion(a, b);
        }
    }

    return 0;
}