class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        vector<int> maxProfitUpTo(n);
        maxProfitUpTo[0] = jobs[0].second;
        for (int i = 1; i < n; i++) {
            maxProfitUpTo[i] = max(maxProfitUpTo[i-1], jobs[i].second);
        }
        
        int totalProfit = 0;
        int j = 0;
        int best = 0;
        for (int i = 0; i < m; i++) {
            while (j < n && jobs[j].first <= worker[i]) {
                best = max(best, jobs[j].second);
                j++;
            }
            totalProfit += best;
        }
        
        return totalProfit;
    }
};