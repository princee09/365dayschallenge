class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> left, right;
        for (int i = 0; i < n / 2; i++) left.push_back(nums[i]);
        for (int i = n / 2; i < n; i++) right.push_back(nums[i]);
        vector<int> leftSums = generateSubsetSums(left);
        vector<int> rightSums = generateSubsetSums(right);
        sort(rightSums.begin(), rightSums.end());       
        int minDiff = INT_MAX;
        for (int leftSum : leftSums) {
            int target = goal - leftSum;
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
            if (it != rightSums.end()) {
                minDiff = min(minDiff, abs(leftSum + *it - goal));
            }
            if (it != rightSums.begin()) {
                minDiff = min(minDiff, abs(leftSum + *prev(it) - goal));
            }
            if (minDiff == 0) return 0;
        }
        
        return minDiff;
    }
    
private:
    vector<int> generateSubsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> sums;
        sums.push_back(0);
        for (int i = 0; i < n; i++) {
            int size = sums.size();
            for (int j = 0; j < size; j++) {
                sums.push_back(sums[j] + arr[i]);
            }
        }
        sort(sums.begin(), sums.end());
        sums.erase(unique(sums.begin(), sums.end()), sums.end());
        return sums;
    }
};