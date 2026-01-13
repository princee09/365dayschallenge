class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        int cnt = 0;
        
        for (int l = 0, r = 0; r < n; r++) {
            if (nums[r] == maxVal) cnt++;
            
            while (cnt >= k) {
                res += n - r;
                if (nums[l] == maxVal) cnt--;
                l++;
            }
        }
        
        return res;
    }
};