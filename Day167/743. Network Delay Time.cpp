class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list to represent the graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min-heap: (time, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        // Distance array initialized to "infinity"
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue; // Skip outdated pair

            for (auto& [nei, wt] : graph[node]) {
                if (dist[nei] > time + wt) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
