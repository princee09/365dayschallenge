class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if (n == 0 || m == 0)
            return 0;
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            fill(curr.begin(), curr.end(), 0);
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }

        return prev[m];
    }
};