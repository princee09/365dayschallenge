class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        
        return islands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
            return;
        }
        
        grid[row][col] = '0'; 
        dfs(grid, row - 1, col, rows, cols); 
        dfs(grid, row + 1, col, rows, cols); 
        dfs(grid, row, col - 1, rows, cols); 
        dfs(grid, row, col + 1, rows, cols); 
    }
};