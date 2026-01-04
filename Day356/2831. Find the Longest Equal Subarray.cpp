class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }
        
        int res = 0;
        for (auto& [val, idxs] : pos) {
            int left = 0;
            for (int right = 0; right < idxs.size(); ++right) {
                while (idxs[right] - idxs[left] - (right - left) > k) {
                    ++left;
                }
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};