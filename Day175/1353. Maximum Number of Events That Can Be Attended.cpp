class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = events.size();
        int i = 0, day = 0, count = 0;
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]); // push end day
                i++;
            }
            if (!minHeap.empty()) {
                minHeap.pop(); // attend one event
                count++;
                day++; 
            }
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }

        return count;
    }
};