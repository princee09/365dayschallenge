class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) {
                    dp[i] = 1;  
                } else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    count++;
                }
            } else {
                int firstPart = i / 10;
                int lastDigit = i % 10;
                if (dp[firstPart] == 0 || dp[lastDigit] == 0) {
                    dp[i] = 0;
                } 
                else if (dp[firstPart] == 2 || dp[lastDigit] == 2) {
                    dp[i] = 2;
                    count++;
                }
                else {
                    dp[i] = 1;
                }
            }
        }
        return count;
    }
};