class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0)
                continue;

            string sub = s.substr(0, len);
            bool match = true;

            for (int i = len; i < n; i += len) {
                for (int j = 0; j < len; j++) {
                    if (s[i + j] != sub[j]) {
                        match = false;
                        break;
                    }
                }
                if (!match)
                    break;
            }

            if (match)
                return true;
        }
        return false;
    }
};