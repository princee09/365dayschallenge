class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        const int MOD = 1e9 + 7;
        
        while (i < n || j < m) {
            if (i < n && j < m) {
                if (nums1[i] < nums2[j]) {
                    sum1 += nums1[i];
                    i++;
                } else if (nums1[i] > nums2[j]) {
                    sum2 += nums2[j];
                    j++;
                } else {
                    long long best = max(sum1, sum2) + nums1[i];
                    sum1 = sum2 = best;
                    i++;
                    j++;
                }
            } else if (i < n) {
                sum1 += nums1[i];
                i++;
            } else {
                sum2 += nums2[j];
                j++;
            }
        }
        
        return max(sum1, sum2) % MOD;
    }
};