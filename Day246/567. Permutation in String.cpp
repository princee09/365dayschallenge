class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : s1) {
            freq1[c - 'a']++;
        }
        for (int i = 0; i < n1; i++) {
            freq2[s2[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq1[i] == freq2[i]) {
                count++;
            }
        }
        for (int i = 0; i < n2 - n1; i++) {
            if (count == 26) return true;
            
            int leftChar = s2[i] - 'a';
            int rightChar = s2[i + n1] - 'a';
            
            
            if (freq2[leftChar] == freq1[leftChar]) {
                count--;
            }
            freq2[leftChar]--;
            if (freq2[leftChar] == freq1[leftChar]) {
                count++;
            }
            if (freq2[rightChar] == freq1[rightChar]) {
                count--;
            }
            freq2[rightChar]++;
            if (freq2[rightChar] == freq1[rightChar]) {
                count++;
            }
        }
        
        return count == 26;
    }
};