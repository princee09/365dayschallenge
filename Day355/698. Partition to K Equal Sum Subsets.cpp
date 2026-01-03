class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int target = total / k;
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        for (int num : nums) {
            if (num > target) return false;
        }
        vector<int> subsets(k, 0);
        return backtrack(nums, subsets, 0, target);
    }
    
private:
    bool backtrack(vector<int>& nums, vector<int>& subsets, int index, int target) {
        if (index == nums.size()) {
            for (int sum : subsets) {
                if (sum != target) return false;
            }
            return true;
        }
        int current = nums[index];
        for (int i = 0; i < subsets.size(); i++) {
            if (subsets[i] + current > target) continue;
            if (i > 0 && subsets[i] == subsets[i-1]) continue;
            subsets[i] += current;
            if (backtrack(nums, subsets, index + 1, target)) {
                return true;
            }
            subsets[i] -= current;
            if (subsets[i] == 0) break;
        }
        return false;
    }
};