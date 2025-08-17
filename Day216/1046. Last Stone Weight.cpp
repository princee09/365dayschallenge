class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // heaviest
            int x = pq.top(); pq.pop(); // 2nd heaviest
            if (x != y) {
                pq.push(y - x); // remaining stone with weight y-x
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};