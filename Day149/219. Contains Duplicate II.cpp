class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); ++i) {
            if (indexMap.count(nums[i])) {
                if (i - indexMap[nums[i]] <= k) {
                    return true;
                }
            }
            // Update last seen index
            indexMap[nums[i]] = i;
        }

        return false;
    }
};
