class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        const long long INF = LLONG_MAX / 4;
        
        // dist[i][j] = minimum time to reach (i,j)
        vector<vector<long long>> dist(n, vector<long long>(m, INF));
        dist[0][0] = 0;
        
        // Min‑heap of (time, (i,j))
        using TIII = pair<long long, pair<int,int>>;
        priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
        pq.push({0, {0,0}});
        
        // 4 directions
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!pq.empty()) {
            auto [t, pos] = pq.top(); pq.pop();
            int i = pos.first, j = pos.second;
            if (t > dist[i][j]) continue;
            
            // If reached target, return immediately
            if (i == n-1 && j == m-1) {
                return (int)t;
            }
            
            // Explore neighbours
            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                
                // Wait if needed, then move (1s)
                long long startMove = max(t, (long long)moveTime[ni][nj]);
                long long arrive = startMove + 1;
                
                if (arrive < dist[ni][nj]) {
                    dist[ni][nj] = arrive;
                    pq.push({arrive, {ni,nj}});
                }
            }
        }
        
        // Should always be reachable
        return (int)dist[n-1][m-1];
    }
};