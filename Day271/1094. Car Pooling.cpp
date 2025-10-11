class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers[1001] = {0};
        
        for (const auto& trip : trips) {
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];
        }
        
        int current = 0;
        for (int i = 0; i < 1001; i++) {
            current += passengers[i];
            if (current > capacity) return false;
        }
        
        return true;
    }
};