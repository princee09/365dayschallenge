class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Encode both old and new values in nums[i]
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] + (nums[nums[i]] % n) * n;
        }

        // Step 2: Decode new values (get new value by dividing with n)
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] / n;
        }

        return nums;
    }
};