class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minPrefixSum = 0;
        int prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num;
            minPrefixSum = min(minPrefixSum, prefixSum);
        }
        
        return max(1, 1 - minPrefixSum);
    }
};