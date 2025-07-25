class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        long sumPos = 0;
        bool hasNonNeg = false;
        int maxNeg = INT_MIN;

        for (int x : nums) {
            if (seen.count(x))
                continue;
            seen.insert(x);

            if (x >= 0) {
                sumPos += x;
                hasNonNeg = true;
            } else {
                maxNeg = max(maxNeg, x);
            }
        }
        if (hasNonNeg)
            return (int)sumPos;
        return maxNeg;
    }
};