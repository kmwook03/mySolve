#include <string>
#include <vector>
#include <numeric>

using namespace std;

int dfs(int node, int limit, int& cuts, vector<int>& num, vector<vector<int>>& links) {
    int l_sum = 0, r_sum = 0;
    if (links[node][0] != -1) {
        l_sum = dfs(links[node][0], limit, cuts, num, links);
    }
    if (links[node][1] != -1) {
        r_sum = dfs(links[node][1], limit, cuts, num, links);
    }
    
    if (num[node] + l_sum + r_sum <= limit) {
        return num[node] + l_sum + r_sum;
    } else if (num[node] + min(l_sum, r_sum) <= limit) {
        cuts++;
        return num[node] + min(l_sum, r_sum);
    } else {
        cuts += 2;
        return num[node];
    }
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 1e9, n = num.size(), root = -1;
    vector<int> has_parent(n, 0);
    for (auto& n : links) {
        if (n[0] != -1) has_parent[n[0]] = 1;
        if (n[1] != -1) has_parent[n[1]] = 1;
    }
    for (int i = 0; i < n && root == -1; i++) {
        if (!has_parent[i]) root = i;
    }
    
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        right += num[i];
        if (num[i] > left) left = num[i];
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cuts = 0;
        dfs(root, mid, cuts, num, links);
        if (cuts >= k) {
            left = mid + 1;
        } else {
            right = mid - 1;
            answer = min(answer, mid);
        }
    }
    
    return answer;
}