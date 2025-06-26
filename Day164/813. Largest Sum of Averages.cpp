class Solution {
public:
    int n;
    vector<double> prefixSum;
    vector<vector<double>> dp;

    double average(int i, int j) {
        return (prefixSum[j + 1] - prefixSum[i]) / (j - i + 1);
    }

    double solve(int i, int k, vector<int>& nums) {
        if (dp[i][k] != -1.0) return dp[i][k];
        if (k == 1) return dp[i][k] = average(i, n - 1);

        double maxScore = 0.0;
        for (int j = i; j <= n - k; ++j) {
            double leftAvg = average(i, j);
            double rightScore = solve(j + 1, k - 1, nums);
            maxScore = max(maxScore, leftAvg + rightScore);
        }

        return dp[i][k] = maxScore;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        prefixSum.resize(n + 1, 0.0);
        dp.assign(n, vector<double>(k + 1, -1.0));

        for (int i = 0; i < n; ++i)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        return solve(0, k, nums);
    }
};
