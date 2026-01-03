class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int partitions = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            partitions++;
            int minVal = nums[i];
            int j = i + 1;
            while (j < n && nums[j] - minVal <= k) {
                j++;
            }
            i = j; 
        }
        
        return partitions;
    }
};