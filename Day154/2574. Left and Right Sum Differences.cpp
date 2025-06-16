class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0), rightSum(n, 0), answer(n);

        // Compute leftSum
        for (int i = 1; i < n; ++i) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        // Compute rightSum
        for (int i = n - 2; i >= 0; --i) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        // Compute the absolute differences
        for (int i = 0; i < n; ++i) {
            answer[i] = abs(leftSum[i] - rightSum[i]);
        }

        return answer;
    }
};
