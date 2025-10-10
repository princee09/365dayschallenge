class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9 + 7;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        auto countSumsLessEqual = [&](int target) -> pair<int, long long> {
            int count = 0;
            long long sum = 0;
            
            for (int i = 0; i < n; i++) {
                int j = i;
                while (j < n && prefix[j + 1] - prefix[i] <= target) {
                    count++;
                    sum += prefix[j + 1] - prefix[i];
                    j++;
                }
            }
            return {count, sum};
        };
        
        auto kthSmallestSum = [&](int k) -> int {
            int low = 1, high = prefix[n];
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (countSumsLessEqual(mid).first < k) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            return low;
        };
        auto sumOfFirstK = [&](int k) -> long long {
            if (k == 0) return 0;
            int kth = kthSmallestSum(k);
            auto [count, sum] = countSumsLessEqual(kth - 1);
            sum += (long long)(k - count) * kth;
            return sum;
        };
        
        return (sumOfFirstK(right) - sumOfFirstK(left - 1)) % MOD;
    }
};