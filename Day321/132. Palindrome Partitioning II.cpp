class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i] = i; 
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                    if (i == 0) {
                        dp[j] = 0;
                    } else {
                        dp[j] = min(dp[j], dp[i - 1] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};