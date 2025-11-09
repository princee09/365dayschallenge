class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxUnique = getMaxUniqueLetters(s);
        int result = 0;
        for (int currUnique = 1; currUnique <= maxUnique; currUnique++) {
            result = max(result, longestSubstringWithNUnique(s, k, currUnique));
        }
        
        return result;
    }
    
private:
    int getMaxUniqueLetters(const string& s) {
        bool map[26] = {false};
        int maxUnique = 0;
        for (char c : s) {
            if (!map[c - 'a']) {
                maxUnique++;
                map[c - 'a'] = true;
            }
        }
        return maxUnique;
    }
    
    int longestSubstringWithNUnique(const string& s, int k, int numUnique) {
        int count[26] = {0};
        int start = 0, end = 0;
        int unique = 0, countAtLeastK = 0;
        int result = 0;
        
        while (end < s.length()) {
            if (unique <= numUnique) {
                int idx = s[end] - 'a';
                if (count[idx] == 0) unique++;
                count[idx]++;
                if (count[idx] == k) countAtLeastK++;
                end++;
            }
            else {
                int idx = s[start] - 'a';
                if (count[idx] == k) countAtLeastK--;
                count[idx]--;
                if (count[idx] == 0) unique--;
                start++;
            }
            if (unique == numUnique && unique == countAtLeastK) {
                result = max(result, end - start);
            }
        }
        
        return result;
    }
};