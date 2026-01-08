class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        int res = 0;
        for (int i = 1; i < n; ++i) {
            int roundTrip = 2 * dist[i];
            int lastSend = ((roundTrip - 1) / patience[i]) * patience[i];
            int finishTime = lastSend + roundTrip;
            res = max(res, finishTime);
        }
        return res + 1;
    }
};