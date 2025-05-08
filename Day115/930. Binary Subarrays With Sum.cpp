class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // base case for sum = goal directly

        int sum = 0, result = 0;
        for (int num : nums) {
            sum += num;
            if (prefixCount.find(sum - goal) != prefixCount.end()) {
                result += prefixCount[sum - goal];
            }
            prefixCount[sum]++;
        }

        return result;
    }
};