class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isNonDecreasing(nums)) {
            int n = nums.size();
            int minSum = INT_MAX;
            int minIndex = -1;

            // Step 1: Find the leftmost adjacent pair with the minimum sum
            for (int i = 0; i < n - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIndex = i;
                }
            }

            // Step 2: Replace the pair with their sum
            vector<int> newNums;
            for (int i = 0; i < minIndex; ++i) {
                newNums.push_back(nums[i]);
            }
            newNums.push_back(nums[minIndex] + nums[minIndex + 1]);
            for (int i = minIndex + 2; i < n; ++i) {
                newNums.push_back(nums[i]);
            }

            nums = newNums;
            ++ops;
        }
        return ops;
    }
private:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};
