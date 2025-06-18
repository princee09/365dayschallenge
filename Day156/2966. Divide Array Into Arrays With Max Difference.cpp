class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());              
        vector<vector<int>> res;
        res.reserve(n / 3);
        // Group every 3 consecutve element
        for (int i = 0; i < n; i += 3) {            
            // if the difference between max and min in this triple exceeds k fail
            if (nums[i + 2] - nums[i] > k)
                return {};
            // otherwise push this valid group
            res.emplace_back(initializer_list<int>{nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};