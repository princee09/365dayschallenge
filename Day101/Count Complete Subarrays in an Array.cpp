
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int total_distinct = s.size();
        if (total_distinct == 0) return 0;

        int count = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(2001, 0); // Since nums[i] can be up to 2000
            int current_distinct = 0;
            int j = i;

            while (j < n && current_distinct < total_distinct) {
                int num = nums[j];
                if (freq[num] == 0) {
                    current_distinct++;
                }
                freq[num]++;
                j++;
            }

            if (current_distinct == total_distinct) {
                count += (n - (j - 1));
            }
        }

        return count;
    }
};