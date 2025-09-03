class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long current_sum = 0;
        long long max_sum = 0;
        int n = nums.size();
        
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            current_sum += nums[i];
        }
        if (freq.size() == k) {
            max_sum = current_sum;
        }
        for (int i = k; i < n; i++) {
            int left = nums[i - k];
            freq[left]--;
            if (freq[left] == 0) {
                freq.erase(left);
            }
            current_sum -= left;
            int right = nums[i];
            freq[right]++;
            current_sum += right;
            if (freq.size() == k) {
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                }
            }
        }
        
        return max_sum;
    }
};