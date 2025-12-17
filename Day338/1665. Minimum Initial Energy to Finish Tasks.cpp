class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int result = 0;
        int actual_sum = 0;
        
        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            result = max(result, minimum + actual_sum);
            actual_sum += actual;
        }
        
        return result;
    }
};