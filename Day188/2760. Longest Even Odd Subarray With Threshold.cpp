class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLength = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                int length = 1;

                for (int j = i + 1; j < n; ++j) {
                    if (nums[j] > threshold || (nums[j] % 2 == nums[j - 1] % 2)) {
                        break;
                    }
                    length++;
                }

                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};