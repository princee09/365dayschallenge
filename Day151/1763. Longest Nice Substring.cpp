class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";

        unordered_set<char> st(s.begin(), s.end());

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (st.count(tolower(ch)) && st.count(toupper(ch))) continue;

            // Split at the point where a character is not nice
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            return left.size() >= right.size() ? left : right;
        }

        // If all characters are nice
        return s;
    }
};
