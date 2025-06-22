class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        // Transform s into T with sentinels and separators:
        // e.g. "aba" -> "^#a#b#a#$"
        string T;
        T.reserve(n * 2 + 3);
        T.push_back('^');
        for (char c : s) {
            T.push_back('#');
            T.push_back(c);
        }
        T += "#$";

        int N = T.size();
        vector<int> P(N, 0);      // P[i] = radius of palindrome centered at i
        int center = 0, right = 0; 

        for (int i = 1; i < N - 1; ++i) {
            // Mirror of i around current center
            int mirror = 2*center - i;  
            if (i < right)
                P[i] = min(right - i, P[mirror]);

            // Try to expand palindrome centered at i
            while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
                ++P[i];
            }
            if (i + P[i] > right) {
                center = i;
                right  = i + P[i];
            }
        }
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < N - 1; ++i) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen - 1) / 2;
        return s.substr(start, maxLen);
    }
};