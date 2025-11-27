class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<long long> minPrefix(k, LLONG_MAX);
        minPrefix[0] = 0; 
        long long maxSum = LLONG_MIN;
        for (int j = 0; j < n; j++) {
            int r = (j + 1) % k;
            if (minPrefix[r] != LLONG_MAX) {
                maxSum = max(maxSum, prefix[j + 1] - minPrefix[r]);
            }
            if (prefix[j + 1] < minPrefix[r]) {
                minPrefix[r] = prefix[j + 1];
            }
        }
        return maxSum;
    }
};