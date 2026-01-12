class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m < n) return 0;
        
        vector<int> need(26, 0);
        for (char ch : word2) {
            need[ch - 'a']++;
        }
        
        long long result = 0;
        vector<int> have(26, 0);
        int left = 0;
        for (int right = 0; right < m; right++) {
            have[word1[right] - 'a']++;  
            while (left <= right && isValid(have, need)) {
                result += m - right;
                have[word1[left] - 'a']--;
                left++;
            }
        }      
        return result;
    }
    
private:
    bool isValid(vector<int>& have, vector<int>& need) {
        for (int i = 0; i < 26; i++) {
            if (have[i] < need[i]) {
                return false;
            }
        }
        return true;
    }
};