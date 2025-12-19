class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1]) left++;
        if (left == n - 1) return 0;
        while (right > 0 && nums[right] >= nums[right - 1]) right--;
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = left; i <= right; i++) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        while (left > 0 && nums[left - 1] > minVal) left--;
        while (right < n - 1 && nums[right + 1] < maxVal) right++;
        return right - left + 1;
    }
};