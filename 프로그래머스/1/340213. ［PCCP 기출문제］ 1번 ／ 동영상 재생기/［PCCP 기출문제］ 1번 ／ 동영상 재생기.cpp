#include <string>
#include <vector>
#include <sstream>

using namespace std;

int time_to_sec(string t) {
    stringstream ss(t);
    string token;
    vector<int> time;
    
    while (getline(ss, token, ':'))
        time.push_back(stoi(token));
    
    return time[0]*60 + time[1];
}

string sec_to_mmss(int time) {
    string mm, ss;
    int m = time / 60;
    int s = time - m*60;
    mm = (m < 10) ? "0" + to_string(m) : to_string(m);
    ss = (s < 10) ? "0" + to_string(s): to_string(s);
    
    return mm + ":" + ss;
}

void prev(int& pos) {
    if (pos < 10) 
        pos = 0;
    else 
        pos -= 10;
}

void next(int vid_len, int& pos) {
    if (vid_len - pos < 10)
        pos = vid_len;
    else
        pos += 10;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int vid_len_sec = time_to_sec(video_len);
    int pos_sec = time_to_sec(pos);
    int op_start_sec = time_to_sec(op_start);
    int op_end_sec = time_to_sec(op_end);
    
    for (auto c : commands) {
        if (op_start_sec <= pos_sec && pos_sec <= op_end_sec)
            pos_sec = op_end_sec;
        if (c == "prev")
            prev(pos_sec);
        else if (c == "next")
            next(vid_len_sec, pos_sec);
        if (op_start_sec <= pos_sec && pos_sec <= op_end_sec)
            pos_sec = op_end_sec;
    }
    
    string answer = sec_to_mmss(pos_sec);
    return answer;
}