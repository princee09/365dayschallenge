class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); 

        for (char c : s) {
            if (c == '(') {
                st.push(0); 
            } else {
                int innerScore = st.top(); st.pop();
                int outerScore = st.top(); st.pop();
                int newScore = outerScore + max(2 * innerScore, 1);
                st.push(newScore);
            }
        }

        return st.top();
    }
};