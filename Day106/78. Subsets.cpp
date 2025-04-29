class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        res.reserve(1 << n);               // there are 2^n subsets
        
        // use bit‐mask from 0 to 2^n − 1
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> subset;
            subset.reserve(n);
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(move(subset));
        }
        
        return res;
    }
};
