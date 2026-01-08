class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> scores(n, 0);
        
        for (int i = 0; i < n; i++) {
            scores[edges[i]] += i;
        }
        
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (scores[i] > scores[result]) {
                result = i;
            }
        }
        return result;
    }
};