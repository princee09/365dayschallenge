class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        
        int target = n / 4;
        if (count['Q'] == target && count['W'] == target && 
            count['E'] == target && count['R'] == target) 
            return 0;
        
        int ans = n;
        int l = 0;
        
        for (int r = 0; r < n; r++) {
            count[s[r]]--;
            while (l < n && count['Q'] <= target && count['W'] <= target &&
                   count['E'] <= target && count['R'] <= target) {
                ans = min(ans, r - l + 1);
                count[s[l]]++;
                l++;
            }
        }
        
        return ans;
    }
};