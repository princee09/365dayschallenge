class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        static const int dirs[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };
        
        queue<tuple<int,int,int>> q;
        q.emplace(0, 0, 1);
        grid[0][0] = 1;  
        
        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();
            
            if (r == n - 1 && c == n - 1)
                return dist;
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;            
                    q.emplace(nr, nc, dist + 1);
                }
            }
        }
        
        return -1;  // no path found
    }
};
