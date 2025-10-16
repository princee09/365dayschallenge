class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        
        int ans = 0;
        
        for (int j = n - 1; j >= 0; j--) {
            int maxVal = 0;
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, grid[i][j]);
            }
            ans += maxVal;
        }
        
        return ans;
    }
};