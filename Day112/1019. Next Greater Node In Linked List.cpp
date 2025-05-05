/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // 1) Copy all node values into a vector
        vector<long long> vals;
        for (ListNode* p = head; p; p = p->next) {
            vals.push_back(p->val);
        }
        
        int n = vals.size();
        vector<int> ans(n, 0);
        // stack will hold indices whose next greater hasn’t been found
        stack<int> st;
        
        // 2) Walk through vals and use monotonic stack
        for (int i = 0; i < n; ++i) {
            // Whenever current value is bigger than at stack top,
            // we’ve found the “next greater” for that index.
            while (!st.empty() && vals[i] > vals[st.top()]) {
                ans[st.top()] = vals[i];
                st.pop();
            }
            // Now push this index as a candidate waiting for its next greater
            st.push(i);
        }
        
        // Any indices left in stack have no greater node to the right;
        // their ans[] entries remain 0.
        return ans;
    }
};
