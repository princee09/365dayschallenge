class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        
        for (int a : amount) {
            if (a > 0) {
                pq.push(a);
            }
        }
        
        int time = 0;
        
        while (!pq.empty()) {
            if (pq.size() == 1) {
                time += pq.top();
                break;
            }
            
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            
            time++;
            first--;
            second--;
            if (first > 0) pq.push(first);
            if (second > 0) pq.push(second);
        }
        
        return time;
    }
};