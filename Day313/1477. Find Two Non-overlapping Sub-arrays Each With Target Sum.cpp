class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = 1e9;
        vector<int> dp(n, INF);
        
        int left = 0, sum = 0;
        int minLen = INF, result = INF;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int currLen = right - left + 1;
                dp[right] = currLen;
                if (right > 0) {
                    dp[right] = min(dp[right], dp[right - 1]);
                }
                if (left > 0 && dp[left - 1] != INF) {
                    result = min(result, currLen + dp[left - 1]);
                }
            } else if (right > 0) {
                dp[right] = dp[right - 1];
            }
        }
        
        return result == INF ? -1 : result;
    }
};