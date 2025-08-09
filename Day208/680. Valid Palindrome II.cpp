class Solution {
public:
    bool validPalindrome(const string &s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                return isPalindromeRange(s, i + 1, j) || isPalindromeRange(s, i, j - 1);
            }
        }
        return true;
    }

private:
    bool isPalindromeRange(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};
