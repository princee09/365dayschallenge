class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        
        for (const auto& b : bookings) {
            diff[b[0] - 1] += b[2];
            diff[b[1]] -= b[2];
        }
        
        vector<int> result(n);
        result[0] = diff[0];
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] + diff[i];
        }
        
        return result;
    }
};