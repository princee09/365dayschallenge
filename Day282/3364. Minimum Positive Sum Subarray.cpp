class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int ans = INT_MAX;
        multiset<int> ms;
        
        for (int j = l - 1; j < n; j++) {
            int new_i = j - l + 1;
            if (new_i >= 0) {
                ms.insert(prefix[new_i]);
            }
            int old_i = j - r;
            if (old_i >= 0) {
                ms.erase(ms.find(prefix[old_i]));
            }
            auto it = ms.lower_bound(prefix[j + 1]);
            if (it != ms.begin()) {
                --it;
                int diff = prefix[j + 1] - *it;
                if (diff > 0 && diff < ans) {
                    ans = diff;
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};