class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        long long total = 0;
        for (int v : nums)
            total += v;

        long long left = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (left == total - left - nums[i])
                return i;
            left += nums[i];
        }
        return -1;
    }
};