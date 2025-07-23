class Solution {
public:
    int remove(string &s, char first, char second, int val) {
        stack<char> st;
        int score = 0;

        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop();     // remove the substring
                score += val; // add score
            } else {
                st.push(ch);
            }
        }

        // rebuild the string after removal
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int score = 0;

        if (x > y) {
            score += remove(s, 'a', 'b', x);
            score += remove(s, 'b', 'a', y);
        } else {
            score += remove(s, 'b', 'a', y);
            score += remove(s, 'a', 'b', x);
        }

        return score;
    }
};
