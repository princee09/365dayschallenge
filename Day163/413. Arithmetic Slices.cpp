class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int count = 0;  // slices ending at current index
        int res = 0;    // total slices

        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                count++;           // extend previous slice
                res += count;      // add to total
            } else {
                count = 0;         // reset if not arithmetic
            }
        }

        return res;
    }
};