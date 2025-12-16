class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        if (k >= n/2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1]) {
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }
        vector<int> dp(k + 1, 0);
        vector<int> minCost(k + 1, prices[0]); 
        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= k; t++) {
                minCost[t] = min(minCost[t], prices[i] - dp[t-1]);
                dp[t] = max(dp[t], prices[i] - minCost[t]);
            }
        }
        
        return dp[k];
    }
};