class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        int eaten = 0;
        
        for (int day = 0; day < n || !pq.empty(); ++day) {
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }
            while (!pq.empty() && pq.top().first <= day) {
                pq.pop();
            }
            if (!pq.empty()) {
                auto [expiry, count] = pq.top();
                pq.pop();
                eaten++;
                if (count > 1) {
                    pq.push({expiry, count - 1});
                }
            }
        }
        
        return eaten;
    }
};