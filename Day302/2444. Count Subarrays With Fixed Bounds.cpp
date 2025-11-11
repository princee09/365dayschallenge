class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int n = nums.size();
        int lastMin = -1, lastMax = -1;
        int leftBound = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftBound = i;
                lastMin = -1;
                lastMax = -1;
                continue;
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            if (lastMin != -1 && lastMax != -1) {
                int validStart = min(lastMin, lastMax);
                count += (validStart - leftBound);
            }
        }
        
        return count;
    }
};