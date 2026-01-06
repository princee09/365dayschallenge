class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double minAvg = DBL_MAX;
        
        for (int i = 0; i < n / 2; i++) {
            double avg = (nums[i] + nums[n - 1 - i]) / 2.0;
            minAvg = min(minAvg, avg);
        }
        
        return minAvg;
    }
};