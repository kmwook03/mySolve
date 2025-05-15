#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long solving(vector<int>& diffs, vector<int>& times, int curr_level)
{
    long long clear_time = 0;
    for (auto i=0; i<diffs.size(); i++)
    {
        if (diffs[i]<=curr_level) clear_time += times[i];
        else
        {
            int wrongs = diffs[i] - curr_level;
            int time_prev = 0;
            if (i>0) time_prev = times[i-1];
            int waste_time = (times[i]+time_prev)*wrongs;
            clear_time += (times[i] + waste_time);
        }
    }
    return clear_time;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long level = 0;
    // int mean_level = accumulate(diffs.begin(), diffs.end(), 0) / diffs.size();
    int right = *max_element(diffs.begin(), diffs.end());
    int left = *min_element(diffs.begin(), diffs.end());
    // int prev_level = 0;
    
    while (left <= right)
    {
        int mid = (left+right)/2;
        if (solving(diffs, times, mid) <= limit)
        {
            level = mid;
            right = mid-1;
        } else
        {
            left = mid+1;
        }
    }
    return level;
}