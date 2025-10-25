class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string prefix = "";
        
        for (const string& word : words) {
            prefix += word;
            if (prefix.length() > s.length()) {
                return false;
            }
            if (prefix == s) {
                return true;
            }
        }
        
        return prefix == s;
    }
};