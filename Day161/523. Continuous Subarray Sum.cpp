class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIndex;
        modIndex[0] = -1; // base case sum from start is a multiple of k
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (k != 0)
                sum %= k;

            if (modIndex.find(sum) != modIndex.end()) {
                if (i - modIndex[sum] > 1)
                    return true;
            } else {
                modIndex[sum] = i;
            }
        }

        return false;
    }
};