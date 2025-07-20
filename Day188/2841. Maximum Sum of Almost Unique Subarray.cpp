class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> freq;
        long long maxSum = 0, windowSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            windowSum += nums[i];
            freq[nums[i]]++;
            if (i >= k) {
                freq[nums[i - k]]--;
                windowSum -= nums[i - k];
                if (freq[nums[i - k]] == 0) {
                    freq.erase(nums[i - k]);
                }
            }
            if (i >= k - 1) {
                if (freq.size() >= m) {
                    maxSum = max(maxSum, windowSum);
                }
            }
        }

        return maxSum;
    }
};