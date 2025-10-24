class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int total = prefix[n];
        long long ans = 0;
        for (int i = 0; i < n - 2; i++) {
            int sum_left = prefix[i + 1];
            int low = lower_bound(prefix.begin(), prefix.end(), 2 * sum_left) - prefix.begin();
            low = max(low, i + 2); 
            int high = upper_bound(prefix.begin(), prefix.end(), (total + sum_left) / 2) - prefix.begin();
            high = min(high, n); 
            
            if (low < high) {
                ans += (high - low);
            }
        }
        
        return ans % MOD;
    }
};