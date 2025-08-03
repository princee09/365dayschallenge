class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        static const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue< 
            tuple<int,int,int>, 
            vector<tuple<int,int,int>>, 
            greater<tuple<int,int,int>> 
        > pq;
        
        dist[0][0] = 0;
        pq.emplace(0, 0, 0);  
        
        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();
            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }
            if (effort > dist[r][c]) continue;
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                int nextEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                if (nextEffort < dist[nr][nc]) {
                    dist[nr][nc] = nextEffort;
                    pq.emplace(nextEffort, nr, nc);
                }
            }
        }
        
        return 0; 
    }
};
