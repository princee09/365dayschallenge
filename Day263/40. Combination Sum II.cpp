class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, current, result);
        return result;
    }

private:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        if (index >= candidates.size() || target < 0) {
            return;
        }
        current.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index + 1, current, result);
        current.pop_back();
        int next = index + 1;
        while (next < candidates.size() && candidates[next] == candidates[index]) {
            next++;
        }
        dfs(candidates, target, next, current, result);
    }
};