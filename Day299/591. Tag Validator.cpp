class Solution {
public:
    bool isValid(string code) {
        stack<string> tags;
        int n = code.length();
        int i = 0;
        
        while (i < n) {
            if (code[i] == '<') {
                if (i + 1 < n && code[i + 1] == '!') {
                    if (tags.empty()) return false;
                    if (i + 9 > n || code.substr(i, 9) != "<![CDATA[") return false;
                    
                    int j = i + 9;
                    bool found = false;
                    while (j + 2 < n) {
                        if (code[j] == ']' && code[j + 1] == ']' && code[j + 2] == '>') {
                            found = true;
                            break;
                        }
                        j++;
                    }
                    if (!found) return false;
                    i = j + 3;
                } 
                else if (i + 1 < n && code[i + 1] == '/') {
                    int j = code.find('>', i);
                    if (j == string::npos) return false;
                    
                    string tagName = code.substr(i + 2, j - i - 2);
                    if (tags.empty() || tags.top() != tagName) return false;
                    
                    tags.pop();
                    i = j + 1;
                    if (tags.empty() && i < n) return false;
                } 
                else {
                    int j = code.find('>', i);
                    if (j == string::npos) return false;
                    
                    string tagName = code.substr(i + 1, j - i - 1);
                    if (!isValidTag(tagName)) return false;
                    
                    tags.push(tagName);
                    i = j + 1;
                }
            } 
            else {
                if (tags.empty()) return false;
                i++;
            }
        }
        
        return tags.empty();
    }
    
private:
    bool isValidTag(const string& tag) {
        if (tag.empty() || tag.size() > 9) return false;
        for (char c : tag) {
            if (c < 'A' || c > 'Z') return false;
        }
        return true;
    }
};