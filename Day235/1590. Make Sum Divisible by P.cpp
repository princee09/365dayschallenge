class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) total_sum += num;
        int r = total_sum % p;
        if (r == 0) return 0;

        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        long long curr = 0;
        int n = nums.size();
        int ans = n; 
        for (int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;
            int target = (curr - r + p) % p;
            if (prefix_map.find(target) != prefix_map.end()) {
                int i = prefix_map[target];
                ans = min(ans, j - i);
            }
            prefix_map[curr] = j;
        }

        return (ans == n) ? -1 : ans;
    }
};