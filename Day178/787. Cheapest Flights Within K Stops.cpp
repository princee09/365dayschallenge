class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], cost = flight[2];
            graph[u].push_back({v, cost});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});
        vector<int> dist(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        dist[src] = 0;
        stops[src] = 0;

        while (!pq.empty()) {
            auto [cost, u, stop] = pq.top();
            pq.pop();

            if (u == dst) return cost;
            if (stop > k) continue;

            for (auto& [v, price] : graph[u]) {
                int newCost = cost + price;
                if (newCost < dist[v] || stop + 1 < stops[v]) {
                    dist[v] = newCost;
                    stops[v] = stop + 1;
                    pq.push({newCost, v, stop + 1});
                }
            }
        }

        return -1;
    }
};