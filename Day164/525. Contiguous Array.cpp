class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;  // Base case sum 0 at index -1
        int maxLen = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // Convert 0 to -1 to use sum logic
            sum += (nums[i] == 1 ? 1 : -1);
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;  // Store the first occurrence of this sum
            }
        }

        return maxLen;
    }
};