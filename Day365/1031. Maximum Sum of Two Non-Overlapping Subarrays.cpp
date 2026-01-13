class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen), 
                   helper(nums, secondLen, firstLen));
    }
    
private:
    int helper(vector<int>& nums, int L, int M) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= L) sum -= nums[i - L];
            if (i >= L - 1) left[i] = max((i > 0 ? left[i - 1] : 0), sum);
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            if (i + M < n) sum -= nums[i + M];
            if (i + M - 1 < n) right[i] = max((i + 1 < n ? right[i + 1] : 0), sum);
        }
        int res = 0;
        for (int i = L - 1; i < n - M; i++) {
            res = max(res, left[i] + right[i + 1]);
        }
        
        return res;
    }
};