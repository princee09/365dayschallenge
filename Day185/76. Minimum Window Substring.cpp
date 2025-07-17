class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n)
            return "";
        vector<int> need(128, 0), window(128, 0);
        for (char c : t)
            need[c]++;

        int required = 0;
        for (int i = 0; i < 128; i++)
            if (need[i] > 0)
                required++;

        int formed = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < m) {
            char c = s[right];
            window[c]++;
            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }
            right++;
            while (formed == required) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                char d = s[left];
                window[d]--;
                if (need[d] > 0 && window[d] < need[d]) {
                    formed--;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};