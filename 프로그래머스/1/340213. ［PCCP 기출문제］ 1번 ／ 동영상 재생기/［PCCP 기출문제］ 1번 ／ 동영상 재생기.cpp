#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int v_len = (video_len[0] - '0')*1000 + (video_len[1] - '0')*100 + 
                (video_len[3] - '0')*10 + (video_len[4] - '0');
    int op_s = (op_start[0] - '0')*1000 + (op_start[1] - '0')*100 + 
                (op_start[3] - '0')*10 + (op_start[4] - '0');
    int op_e = (op_end[0] - '0')*1000 + (op_end[1] - '0')*100 + 
                (op_end[3] - '0')*10 + (op_end[4] - '0');
    int p = (pos[0] - '0')*1000 + (pos[1] - '0')*100 + 
            (pos[3] - '0')*10 + (pos[4] - '0');
    for (const auto cmd : commands)
    {
        if (p>=op_s && p<=op_e) p=op_e;
        if (cmd == "next")
        {
            int next_p = ((p+10)%100 >= 60) ? (p+50) : (p+10);
            p = (next_p>=v_len) ? (v_len) : (next_p);
        }
        if (cmd == "prev")
        {
            int next_p = ((p-10)%100 >= 60) ? (p-50) : (p-10);
            p = (next_p<=0) ? (0) : (next_p);
        }
    }
    if (p>=op_s && p<=op_e) p=op_e;
    string sp = to_string(p);
    if (sp.length() < 4)
    {
        int now_len = sp.length();
        for (int i=0; i<4-now_len; i++) sp = "0" + sp;
    }
    sp = sp.substr(0,2) + ":" + sp.substr(2,3);
    return sp;
}