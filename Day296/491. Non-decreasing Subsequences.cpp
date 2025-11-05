class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
    
private:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() >= 2) {
            result.push_back(current);
        }
        
        unordered_set<int> used; 
        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            if (!current.empty() && nums[i] < current.back()) continue;
            
            used.insert(nums[i]);
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back();
        }
    }
};