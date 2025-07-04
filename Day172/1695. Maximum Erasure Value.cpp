class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
    int left = 0, right = 0, maxScore = 0, currentSum = 0;

    while (right < nums.size()) {
        if (seen.find(nums[right]) == seen.end()) {
            seen.insert(nums[right]);
            currentSum += nums[right];
            maxScore = max(maxScore, currentSum);
            right++;
        } else {
            // Remove from left until duplicate is removed
            seen.erase(nums[left]);
            currentSum -= nums[left];
            left++;
        }
    }

    return maxScore;
    }
};