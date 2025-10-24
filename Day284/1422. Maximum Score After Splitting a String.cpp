class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        int zeros = 0, ones = totalOnes;
        int maxScore = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            
            maxScore = max(maxScore, zeros + ones);
        }
        
        return maxScore;
    }
};