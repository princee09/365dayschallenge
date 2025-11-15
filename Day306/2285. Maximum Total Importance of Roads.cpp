class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(), degree.end(), greater<long long>());
        long long totalImportance = 0;
        long long value = n;
        for (int i = 0; i < n; i++) {
            totalImportance += degree[i] * value;
            value--;
        }
        
        return totalImportance;
    }
};