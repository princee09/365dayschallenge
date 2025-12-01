class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                long long val = (long long)dp[i] + (long long)dp[i - coin];
                dp[i] = (int)val;
            }
        }
        
        return dp[amount];
    }
};