#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> fibo(n+1);
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i=3; i<=n; i++) fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567;
    answer = fibo[n];
    return answer;
}