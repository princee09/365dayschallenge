class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        vector<int> prefix0(n + 1, 0), prefix1(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix0[i + 1] = prefix0[i] + (s[i] == '0');
            prefix1[i + 1] = prefix1[i] + (s[i] == '1');
        }
        
        int count = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int zeros = prefix0[r + 1] - prefix0[l];
                int ones = prefix1[r + 1] - prefix1[l];
                if (zeros <= k || ones <= k) {
                    count++;
                }
            }
        }
        return count;
    }
};