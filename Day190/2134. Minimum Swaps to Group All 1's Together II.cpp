class Solution {
public:
    int minSwaps(vector<int>& nums) {
     int totalOnes = 0;
        int n = nums.size();
        for (int num : nums) {
            totalOnes += num;
        }

        if (totalOnes == 0 || totalOnes == n) return 0;
        int maxOnesInWindow = 0, currentOnes = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (i < totalOnes) {
                currentOnes += nums[i % n];
            } else {
                currentOnes += nums[i % n];
                currentOnes -= nums[(i - totalOnes) % n];
            }
            if (i >= totalOnes - 1) {
                maxOnesInWindow = max(maxOnesInWindow, currentOnes);
            }
        }

        return totalOnes - maxOnesInWindow;   
    }
};