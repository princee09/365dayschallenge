class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> graph;

    double dfs(string curr, string target, unordered_set<string>& visited, double product) {
        if (curr == target) return product;
        visited.insert(curr);

        for (auto& [neighbor, weight] : graph[curr]) {
            if (!visited.count(neighbor)) {
                double result = dfs(neighbor, target, visited, product * weight);
                if (result != -1.0) return result;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0], B = equations[i][1];
            double val = values[i];
            graph[A].push_back({B, val});
            graph[B].push_back({A, 1.0 / val});
        }
        vector<double> result;
        for (auto& q : queries) {
            string start = q[0], end = q[1];

            if (!graph.count(start) || !graph.count(end)) {
                result.push_back(-1.0);
                continue;
            }

            if (start == end) {
                result.push_back(1.0); 
                continue;
            }

            unordered_set<string> visited;
            double ans = dfs(start, end, visited, 1.0);
            result.push_back(ans);
        }
        return result;
    }
};
