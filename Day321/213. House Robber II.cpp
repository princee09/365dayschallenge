class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        auto robHelper = [](vector<int>& nums, int l, int r) {
            int prev = 0, curr = 0;
            for (int i = l; i <= r; i++) {
                int temp = curr;
                curr = max(curr, prev + nums[i]);
                prev = temp;
            }
            return curr;
        };
        
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }
};