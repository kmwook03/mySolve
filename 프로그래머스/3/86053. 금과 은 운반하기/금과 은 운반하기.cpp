#include <string>
#include <vector>

using namespace std;

bool isPossible(long long T, int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t) {
    long long tot_g = 0;
    long long tot_s = 0;
    long long tot_m = 0;
    
    for (size_t i = 0; i < g.size(); i++) {
        long long cnt = (T + t[i]) / (t[i] * 2);
        long long max_w = cnt * w[i];
        
        tot_g += ((long long)g[i] < max_w) ? (long long)g[i] : max_w;
        tot_s += ((long long)s[i] < max_w) ? (long long)s[i] : max_w;
        tot_m += ((long long)(g[i] + s[i]) < max_w) ? (long long)(g[i] + s[i]) : max_w;
    }
    
    return (tot_g >= a && tot_s >= b && tot_m >= (a + b));
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    long long left = 0, right = 4e14;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (isPossible(mid, a, b, g, s, w, t)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}