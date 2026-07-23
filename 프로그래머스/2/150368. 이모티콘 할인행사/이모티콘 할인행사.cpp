#include <string>
#include <vector>

using namespace std;

vector<vector<int>> discounted;
int max_plus = -1, max_revenue = -1;

vector<int> evaluate(vector<vector<int>>& users, vector<vector<int>>& d_emos) {
    vector<int> cost(2, 0);
    for (auto& u : users) {
        int accum_money = 0;
        for (auto& e : d_emos) {
            if (e[0] >= u[0]) accum_money += e[1];
            if (accum_money >= u[1]) {
                accum_money = 0;
                cost[0]++;
                break;
            }
        }
        cost[1] += accum_money;
    }
    return cost;
}

void dfs(int depth, vector<vector<int>>& d_emos, vector<vector<int>>& users) {
    if (depth == discounted.size()) {
        vector<int> result = evaluate(users, d_emos);
        if (result[0] > max_plus) {
            max_plus = result[0];
            max_revenue = result[1];
        } else if (result[0] == max_plus && result[1] > max_revenue) {
            max_revenue = result[1];
        }
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int ratio = (i+1)*10, price = discounted[depth][i];
        d_emos.push_back({ratio, price});
        dfs(depth+1, d_emos, users);
        d_emos.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    int n = users.size(), m = emoticons.size();
    discounted.assign(m, vector<int>(4, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 4; j++)
            discounted[i][j] = emoticons[i]/100 * (100 - (j+1)*10);
    
    vector<vector<int>> d_emos;
    dfs(0, d_emos, users);
    vector<int> answer = {max_plus, max_revenue};
    return answer;
}