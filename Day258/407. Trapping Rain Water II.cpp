class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
    
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int water = 0;
        int maxHeight = 0; 
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            
            int height = cell[0];
            int row = cell[1];
            int col = cell[2];
            
            maxHeight = max(maxHeight, height);
            
            for (auto& dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    
                    if (heightMap[newRow][newCol] < maxHeight) {
                        water += maxHeight - heightMap[newRow][newCol];
                    }
                    pq.push({heightMap[newRow][newCol], newRow, newCol});
                }
            }
        }
        
        return water;
    }
};