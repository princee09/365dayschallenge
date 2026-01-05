class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results(n - k + 1, -1);      
        for (int i = 0; i <= n - k; i++) {
            bool isValid = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                results[i] = nums[i + k - 1]; 
            }
        }
        return results;
    }
};