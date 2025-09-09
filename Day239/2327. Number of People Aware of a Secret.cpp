class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n+1, 0);
        vector<long long> share(n+2, 0);
        dp[1] = 1;
        share[1 + delay] += 1;
        share[1 + forget] -= 1;
        
        for (int i = 2; i <= n; i++) {
            share[i] = (share[i] + share[i-1]) % MOD;
            dp[i] = share[i];
            if (i + delay <= n) {
                share[i + delay] = (share[i + delay] + dp[i]) % MOD;
            }
            if (i + forget <= n) {
                share[i + forget] = (share[i + forget] - dp[i] + MOD) % MOD;
            }
        }
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};