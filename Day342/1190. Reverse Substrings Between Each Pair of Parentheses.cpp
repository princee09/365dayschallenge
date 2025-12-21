class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push(""); 
        for (char ch : s) {
            if (ch == '(') {
                st.push(""); 
            } else if (ch == ')') {
                string topStr = st.top();
                st.pop();
                reverse(topStr.begin(), topStr.end());
                st.top() += topStr; 
            } else {
                st.top() += ch; 
            }
        }
        
        return st.top();
    }
};