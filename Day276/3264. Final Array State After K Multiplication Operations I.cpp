class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        
        for (int op = 0; op < k; op++) {
            int minVal = nums[0];
            int minIndex = 0;
            
            for (int i = 1; i < n; i++) {
                if (nums[i] < minVal) {
                    minVal = nums[i];
                    minIndex = i;
                }
            }
            
            nums[minIndex] = nums[minIndex] * multiplier;
        }
        
        return nums;
    }
};\