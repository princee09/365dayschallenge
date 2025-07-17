class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res;
        if (n < m)
            return res;
        vector<int> freqP(26, 0), freqS(26, 0);
        for (int i = 0; i < m; i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        if (freqP == freqS)
            res.push_back(0);
        for (int i = m; i < n; i++) {
            freqS[s[i] - 'a']++;
            freqS[s[i - m] - 'a']--;
            if (freqP == freqS)
                res.push_back(i - m + 1);
        }
        return res;
    }
};