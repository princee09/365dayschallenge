class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            // move i forward till alphanumeric
            while (i < j && !isalnum(s[i])) i++;
            // move j backward till alphanumeric
            while (i < j && !isalnum(s[j])) j--;
            
            // compare lowercase
            if (i < j && tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};