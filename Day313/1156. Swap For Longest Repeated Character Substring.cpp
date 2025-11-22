class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> count(26, 0);
        for (char c : text) {
            count[c - 'a']++;
        }
        int maxLen = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c - 'a'] == 0) continue;
            
            int left = 0, right = 0;
            int diffCount = 0; 
            int currCount = 0; 
            
            while (right < n) {
                if (text[right] == c) {
                    currCount++;
                } else {
                    diffCount++;
                }
                while (diffCount > 1) {
                    if (text[left] == c) {
                        currCount--;
                    } else {
                        diffCount--;
                    }
                    left++;
                }
                int windowLen = right - left + 1;
                if (currCount + diffCount <= count[c - 'a']) {
                    maxLen = max(maxLen, windowLen);
                } else {
                    maxLen = max(maxLen, windowLen - 1);
                }
                
                right++;
            }
        }
        
        return maxLen;
    }
};