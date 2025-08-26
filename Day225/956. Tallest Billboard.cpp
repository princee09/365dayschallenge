class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;                  
        for (int r : rods) {
            auto cur = dp;
            for (auto [d, h] : cur) {
                // first opt is add rod to left side
                dp[d + r] = max(dp[d + r], h + r);

                // 2nd is add rod to right side
                int newDiff = abs(d - r);
                dp[newDiff] = max(dp[newDiff], h + max(0, r - d));
            }
        }

        return dp[0]; // equal supports
    }
};