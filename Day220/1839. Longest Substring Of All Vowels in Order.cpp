class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int ans = 0, length = 1, count = 1; 

        for (int i = 1; i < n; i++) {
            if (word[i] >= word[i-1]) {
                length++;
                if (word[i] > word[i-1]) {
                    count++;  
                }
            } else {
                length = 1;
                count = 1;
            }
            if (count == 5) {
                ans = max(ans, length);
            }
        }
        return ans;
    }
};