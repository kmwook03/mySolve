#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void traversal(int min_x, int max_x, vector<vector<int>>& nodeinfo, vector<vector<int>>& answer) {
    int root_idx = -1;
    for (int i = 0; i < nodeinfo.size(); i++) {
        if (min_x < nodeinfo[i][0] && nodeinfo[i][0] < max_x) {
            root_idx = i;
            break;
        }
    }
    if (root_idx == -1) return;
    
    // 전위
    answer[0].push_back(nodeinfo[root_idx][2]);
    
    traversal(min_x, nodeinfo[root_idx][0], nodeinfo, answer);
    traversal(nodeinfo[root_idx][0], max_x, nodeinfo, answer);
    
    // 후위
    answer[1].push_back(nodeinfo[root_idx][2]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    int n = nodeinfo.size();
    for (int i = 0; i < n; i++) nodeinfo[i].push_back(i+1);
    sort(nodeinfo.begin(), nodeinfo.end(), 
        [](auto& a, auto& b){
            return (a[1] == b[1]) ? a[0] < b[0] : a[1] > b[1] ;
        });
    traversal(-1, 100001, nodeinfo, answer);
    return answer;
}