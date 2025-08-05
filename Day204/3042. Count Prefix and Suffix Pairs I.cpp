class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            const string& s1 = words[i];
            int len1 = s1.size();
            
            for (int j = i + 1; j < n; ++j) {
                const string& s2 = words[j];
                int len2 = s2.size();
                if (len2 < len1) 
                    continue;
                if (s2.compare(0, len1, s1) != 0) 
                    continue;
                if (s2.compare(len2 - len1, len1, s1) != 0) 
                    continue;
                ++count;
            }
        }
        
        return count;
    }
};