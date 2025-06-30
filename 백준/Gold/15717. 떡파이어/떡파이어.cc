#include <iostream>
#include <vector>

using namespace std;

long long power(long long a, long long b, long long m) {
    long long result = 1;
    a = a%m;

    while (b>0) {
        if (b%2) result = (result*a)%m;
        a = (a*a)%m;
        b /= 2;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    if (n==0) cout << 1 << '\n';
    else cout << power(2, n-1, 1000000007) << '\n';
    
    return 0;
}