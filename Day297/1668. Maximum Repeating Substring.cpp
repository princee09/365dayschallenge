class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.length();
        int m = word.length();
        vector<int> dp(n + 1, 0);
        int maxK = 0;
        
        for (int i = m; i <= n; i++) {
            if (sequence.substr(i - m, m) == word) {
                dp[i] = dp[i - m] + 1;
                maxK = max(maxK, dp[i]);
            }
        }
        
        return maxK;
    }
};