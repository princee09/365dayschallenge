class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> nextGreater;
        stack<int> st;
        // Build next-greater map for every element in nums2
        for (int i = 0; i < n; ++i) {
            int cur = nums2[i];
            // While current element is greater than stack top,
            // it is the next greater for that top
            while (!st.empty() && cur > st.top()) {
                nextGreater[st.top()] = cur;
                st.pop();
            }
            st.push(cur);
        }
        // Elements left in stack have no greater element to their right
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        // Build result for nums1 using the map
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int x : nums1) {
            ans.push_back(nextGreater[x]);
        }
        return ans;
    }
};