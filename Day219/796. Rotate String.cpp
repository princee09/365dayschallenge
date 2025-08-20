class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if (n != (int)goal.length())
            return false;
        for (int i = 0; i < n; ++i) {
            bool match = true;
            for (int j = 0; j < n; ++j) {
                char c = s[(i + j) % n];
                if (c != goal[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                return true;
        }
        return false;
    }
};