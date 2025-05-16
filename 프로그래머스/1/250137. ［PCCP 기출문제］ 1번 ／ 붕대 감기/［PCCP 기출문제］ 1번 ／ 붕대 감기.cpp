#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int t = bandage[0];
    int healPsec = bandage[1];
    int extHeal = bandage[2];
    int cumulative_time = 0;
    int full_hp = health;
    int time = 0;

    for (auto atk : attacks)
    {
        cumulative_time = atk[0] - time -1;
        answer += healPsec*(cumulative_time);
        if (cumulative_time >= t)
        {
            answer += extHeal*(cumulative_time/t);
        }
        if (answer > full_hp) answer = full_hp;
        answer -= atk[1];
        if (answer <= 0) return -1;
        cumulative_time = 0;
        time = atk[0];
        cout << answer << " ";
    }
    cout << endl;
    return answer;
}