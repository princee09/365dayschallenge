class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.size() - 1;
        int maxPairSum = 0;
        while (left < right) {
            int currentPairSum = nums[left] + nums[right];
            maxPairSum = max(maxPairSum, currentPairSum);
            left++;
            right--;
        }
        
        return maxPairSum;
    }
};