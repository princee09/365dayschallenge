class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int current_max = nums[0];
        int current_min = nums[0];
        int total_sum = nums[0];
        
        for (int i = 1; i < n; i++) {
            total_sum += nums[i];
            
            current_max = max(nums[i], current_max + nums[i]);
            max_so_far = max(max_so_far, current_max);
            current_min = min(nums[i], current_min + nums[i]);
            min_so_far = min(min_so_far, current_min);
        }
        if (max_so_far < 0) {
            return max_so_far;
        }
        
        return max(max_so_far, total_sum - min_so_far);
    }
};