class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; base++) {
            string s = convertToBase(n, base);
            if (!isPalindrome(s)) {
                return false;
            }
        }
        return true;
    }
    
private:
    string convertToBase(int n, int base) {
        string result;
        while (n > 0) {
            result.push_back('0' + (n % base));
            n /= base;
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
    
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};