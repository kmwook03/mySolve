#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int cnt = 0;
    for (int i=0; i<schedules.size(); i++)
    {
        int nowDay = startday;
        int success = 0;
        int safe = ((schedules[i] + 10)%100 < 60) ? schedules[i] + 10 : schedules[i] + 50;
        for (const auto t : timelogs[i])
        {
            if ((nowDay%7>=1 && nowDay%7<=5) && t<=safe)
            {
                success++;
            }
            nowDay++;
        }
        if (success == 5) cnt++;
    }
    return cnt;
}