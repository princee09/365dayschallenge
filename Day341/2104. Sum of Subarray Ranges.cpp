class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum_max = 0, sum_min = 0;
        stack<int> st_max, st_min;
        vector<int> left_max(n), right_max(n);
        vector<int> left_min(n), right_min(n);
        for (int i = 0; i < n; i++) {
            while (!st_max.empty() && nums[st_max.top()] <= nums[i]) {
                st_max.pop();
            }
            left_max[i] = st_max.empty() ? -1 : st_max.top();
            st_max.push(i);
        }
        while (!st_max.empty()) st_max.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st_max.empty() && nums[st_max.top()] < nums[i]) {
                st_max.pop();
            }
            right_max[i] = st_max.empty() ? n : st_max.top();
            st_max.push(i);
        }
        for (int i = 0; i < n; i++) {
            while (!st_min.empty() && nums[st_min.top()] >= nums[i]) {
                st_min.pop();
            }
            left_min[i] = st_min.empty() ? -1 : st_min.top();
            st_min.push(i);
        }
        while (!st_min.empty()) st_min.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st_min.empty() && nums[st_min.top()] > nums[i]) {
                st_min.pop();
            }
            right_min[i] = st_min.empty() ? n : st_min.top();
            st_min.push(i);
        }
        for (int i = 0; i < n; i++) {
            long long count_max = (long long)(i - left_max[i]) * (right_max[i] - i);
            long long count_min = (long long)(i - left_min[i]) * (right_min[i] - i);
            
            sum_max += (long long)nums[i] * count_max;
            sum_min += (long long)nums[i] * count_min;
        }
        
        return sum_max - sum_min;
    }
};