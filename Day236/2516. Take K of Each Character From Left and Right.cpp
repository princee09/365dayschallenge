class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);
        for (char c : s)
            total[c - 'a']++;

        if (total[0] < k || total[1] < k || total[2] < k)
            return -1;

        int maxWindow = 0;
        vector<int> cnt(3, 0);
        int l = 0;
        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;
            while (l <= r && (total[0] - cnt[0] < k || total[1] - cnt[1] < k ||
                              total[2] - cnt[2] < k)) {
                cnt[s[l] - 'a']--;
                l++;
            }

            maxWindow = max(maxWindow, r - l + 1);
        }

        return n - maxWindow;
    }
};