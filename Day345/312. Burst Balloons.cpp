class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }
        n += 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; len++) {
            for (int left = 0; left < n - len; left++) {
                int right = left + len;
                for (int last = left + 1; last < right; last++) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][last] + dp[last][right] + 
                        balloons[left] * balloons[last] * balloons[right]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};