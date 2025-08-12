class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n && k > 0 && nums[i] < 0; ++i, --k) nums[i] = -nums[i];
        long long sum = 0;
        int mn = INT_MAX;
        for(int x : nums) {
            sum += x;
            mn = min(mn, abs(x));
        }
        if(k % 2 == 1) sum -= 2LL * mn;
        return (int)sum;
    }
};