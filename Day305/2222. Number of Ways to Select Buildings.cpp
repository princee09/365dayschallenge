class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.length();
        
        vector<int> prefix_ones(n, 0), suffix_ones(n, 0);
        vector<int> prefix_zeros(n, 0), suffix_zeros(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefix_ones[i] = prefix_ones[i - 1];
                prefix_zeros[i] = prefix_zeros[i - 1];
            }
            if (s[i] == '1') prefix_ones[i]++;
            else prefix_zeros[i]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                suffix_ones[i] = suffix_ones[i + 1];
                suffix_zeros[i] = suffix_zeros[i + 1];
            }
            if (s[i] == '1') suffix_ones[i]++;
            else suffix_zeros[i]++;
        }
        
        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '0') {
                ans += (long long)prefix_ones[i - 1] * suffix_ones[i + 1];
            } else {
                ans += (long long)prefix_zeros[i - 1] * suffix_zeros[i + 1];
            }
        }
        
        return ans;
    }
};