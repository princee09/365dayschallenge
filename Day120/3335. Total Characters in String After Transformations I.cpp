static const int MOD = 1e9 + 7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        // dp_prev[i]: length after k-1 transforms for char 'a'+i
        vector<int> dp_prev(26, 1), dp_curr(26);
        
        // Build dp up to t transforms
        for (int k = 1; k <= t; ++k) {
            // for 'a'..'y'
            for (int i = 0; i < 25; ++i) {
                dp_curr[i] = dp_prev[i + 1];
            }
            // for 'z' -> "ab"
            dp_curr[25] = ( (long long)dp_prev[0] + dp_prev[1] ) % MOD;

            // prepare for next iteration
            dp_prev.swap(dp_curr);
        }
        
        // Sum up results for original string
        long long answer = 0;
        for (char c : s) {
            answer = (answer + dp_prev[c - 'a']) % MOD;
        }
        return (int)answer;
    }
};