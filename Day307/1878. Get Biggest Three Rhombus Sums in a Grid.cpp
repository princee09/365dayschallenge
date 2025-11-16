class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int, greater<int>> topSums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                topSums.insert(grid[i][j]);
                if (topSums.size() > 3) {
                    topSums.erase(prev(topSums.end()));
                }
                for (int k = 1; k <= min(m, n) / 2; k++) {
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n) {
                        break;
                    }
                    
                    int sum = 0;
                    for (int d = 0; d < k; d++) {
                        sum += grid[i - k + d][j + d];    
                        sum += grid[i + d][j + k - d];     
                        sum += grid[i + k - d][j - d];    
                        sum += grid[i - d][j - k + d];     
                    }
                    
                    topSums.insert(sum);
                    if (topSums.size() > 3) {
                        topSums.erase(prev(topSums.end()));
                    }
                }
            }
        }
        
        return vector<int>(topSums.begin(), topSums.end());
    }
};