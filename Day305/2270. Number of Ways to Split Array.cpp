class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0;
        for (int num : nums) total_sum += num;
        
        long long prefix_sum = 0;
        int valid_splits = 0;
        
        for (int i = 0; i < n - 1; i++) {
            prefix_sum += nums[i];
            if (prefix_sum >= total_sum - prefix_sum) {
                valid_splits++;
            }
        }
        
        return valid_splits;
    }
};