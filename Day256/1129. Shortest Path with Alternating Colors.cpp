class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n), blueGraph(n);
        
        for (const auto& edge : redEdges) {
            redGraph[edge[0]].push_back(edge[1]);
        }
        
        for (const auto& edge : blueEdges) {
            blueGraph[edge[0]].push_back(edge[1]);
        }
        vector<int> result(n, -1);
        result[0] = 0; 
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        
        queue<vector<int>> q;
        q.push({0, -1, 0}); 
        visited[0][0] = visited[0][1] = true;
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            int node = current[0];
            int lastColor = current[1];
            int dist = current[2];
            
            if (result[node] == -1) {
                result[node] = dist;
            }
            
            if (lastColor != 1) { 
                for (int neighbor : blueGraph[node]) {
                    if (!visited[neighbor][1]) {
                        visited[neighbor][1] = true;
                        q.push({neighbor, 1, dist + 1});
                    }
                }
            }
            
            if (lastColor != 0) { 
                for (int neighbor : redGraph[node]) {
                    if (!visited[neighbor][0]) {
                        visited[neighbor][0] = true;
                        q.push({neighbor, 0, dist + 1});
                    }
                }
            }
        }
        
        return result;
    }
};