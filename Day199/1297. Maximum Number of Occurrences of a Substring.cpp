class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string, int> freq;
        freq.reserve(n);
        
        vector<int> cnt(26, 0);
        int unique = 0, ans = 0;
        for (int i = 0; i < minSize; ++i) {
            if (cnt[s[i] - 'a']++ == 0)
                ++unique;
        }
        if (unique <= maxLetters) {
            string sub = s.substr(0, minSize);
            ans = ++freq[sub];
        }
        for (int i = minSize; i < n; ++i) {
            if (cnt[s[i] - 'a']++ == 0)
                ++unique;
            if (--cnt[s[i - minSize] - 'a'] == 0)
                --unique;
            
            if (unique <= maxLetters) {
                string sub = s.substr(i - minSize + 1, minSize);
                ans = max(ans, ++freq[sub]);
            }
        }
        
        return ans;
    }
};