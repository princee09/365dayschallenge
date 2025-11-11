class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int left = 0;
        long long currentSum = 0;
        int maxRobots = 0;
        deque<int> dq;
        
        for (int right = 0; right < n; right++) {
            currentSum += runningCosts[right];
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
            long long currentCost = chargeTimes[dq.front()] + (right - left + 1) * currentSum;
            
            while (currentCost > budget && left <= right) {
                currentSum -= runningCosts[left];
                
                if (!dq.empty() && dq.front() == left) {
                    dq.pop_front();
                }
                
                left++;
                if (left <= right) {
                    currentCost = chargeTimes[dq.front()] + (right - left + 1) * currentSum;
                }
            }
            maxRobots = max(maxRobots, right - left + 1);
        }
        
        return maxRobots;
    }
};