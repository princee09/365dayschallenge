class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 up to n
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2LL) % MOD;
        }

        int left = 0, right = n - 1;
        int result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                // All subsequences between left and right are valid
                result = (result + power[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};
