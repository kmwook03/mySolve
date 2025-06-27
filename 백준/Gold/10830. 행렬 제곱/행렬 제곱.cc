#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> multiplication(vector<vector<long>> m1, vector<vector<long>> m2, long n) {
    vector<vector<long>> mul_M(n, vector<long>(n, 0));
    long sum = 0;
    for (auto k=0; k<n; k++) {
        for (auto i=0; i<n; i++) {
            long r = m1[i][k];
            for (auto j=0; j<n; j++) {
                mul_M[i][j] = (mul_M[i][j] + (1LL*r*m2[k][j])%1000)%1000;
            }
        }
    }

    return mul_M;
}

vector<vector<long>> mPower(vector<vector<long>> matrix, long n, long b) {
    if (b==1) {
        for (auto i=0; i<n; i++) {
            for (auto j=0; j<n; j++) {
                matrix[i][j] %= 1000;
            }
        }
        return matrix;
    }
    vector<vector<long>> half = mPower(matrix, n, b/2);
    vector<vector<long>> result = multiplication(half, half, n);
    
    if (b%2) {
        result = multiplication(result, matrix, n);
    }

    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long n, b;

    cin >> n >> b;

    vector<vector<long>> matrix;
    vector<vector<long>> pow;
    for (auto i=0; i<n; i++) {
        vector<long> row;
        for (auto j=0; j<n; j++) {
            int a;
            cin >> a;
            row.emplace_back(a);
        }
        matrix.emplace_back(row);
    }

    pow = mPower(matrix, n, b);

    for (auto i=0; i<n; i++) {
        for (auto j=0; j<n; j++) {
            cout << pow[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}