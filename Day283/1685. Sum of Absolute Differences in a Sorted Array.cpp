class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int leftSum = prefix[i]; 
            int rightSum = prefix[n] - prefix[i + 1]; 
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            result[i] = (nums[i] * leftCount - leftSum) + (rightSum - nums[i] * rightCount);
        }
        
        return result;
    }
};