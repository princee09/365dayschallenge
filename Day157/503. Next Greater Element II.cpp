class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;  // will store indices
        
        // Traverse twice for circular effect
        for (int i = 0; i < 2 * n; ++i) {
            int cur = nums[i % n];
            // While current element is greater than element at stack top index
            while (!st.empty() && nums[st.top()] < cur) {
                res[st.top()] = cur;
                st.pop();
            }
            // Only push indices from the first pass
            if (i < n) {
                st.push(i);
            }
        }
        
        return res;
    }
};