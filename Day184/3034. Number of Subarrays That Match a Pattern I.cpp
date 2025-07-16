class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
         int n = nums.size();
        int m = pattern.size();
        int count = 0;
        for (int i = 0; i + m < n; ++i) {
            bool matches = true;
            for (int k = 0; k < m; ++k) {
                int a = nums[i + k];
                int b = nums[i + k + 1];
                
                if (pattern[k] == 1) {
                    if (!(b > a)) {
                        matches = false;
                        break;
                    }
                }
                else if (pattern[k] == 0) {
                    // must be equal
                    if (!(b == a)) {
                        matches = false;
                        break;
                    }
                }
                else {
                    if (!(b < a)) {
                        matches = false;
                        break;
                    }
                }
            }
            
            if (matches) {
                ++count;
            }
        }
        
        return count;
    }
};