class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            if (num > 0) {
                pq.push(num);
            }
        }
        int operations = 0;
        while (!pq.empty()) {
            int currentMin = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == currentMin) {
                pq.pop();
            }
            
            operations++;
            
        }
        
        return operations;
    }
};