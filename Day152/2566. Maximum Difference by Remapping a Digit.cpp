class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string max_str = s;
        char target = ' ';
        for (char c : s) {
            if (c != '9') {
                target = c;
                break;
            }
        }
        if (target != ' ') {
            for (char &c : max_str) {
                if (c == target) {
                    c = '9';
                }
            }
        }
        string min_str = s;
        char first = s[0];
        for (char &c : min_str) {
            if (c == first) {
                c = '0';
            }
        }
        int max_val = stoi(max_str);
        int min_val = stoi(min_str);
        return max_val - min_val;
    }
};