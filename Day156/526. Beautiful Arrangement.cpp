class Solution {
    int n;
    vector<int> memo;  // memo[mask] = number of ways from this mask
public:
    int countArrangement(int N) {
        n = N;
        memo.assign(1 << n, -1);
        // start with mask = 0 (no numbers used), position = 1
        return dfs(0, 1);
    }

    // mask: bit i (0‑indexed) is 1 if number (i+1) is already used
    // pos: next position to fill (1‑indexed)
    int dfs(int mask, int pos) {
        if (pos > n) return 1;              
        if (memo[mask] != -1) return memo[mask];

        int ways = 0;
        // try every number from 1…n
        for (int num = 1; num <= n; ++num) {
            int bit = 1 << (num - 1);
            if ((mask & bit) == 0) {         // if num is unused
                // check beautiful condition
                if (num % pos == 0 || pos % num == 0) {
                    ways += dfs(mask | bit, pos + 1);
                }
            }
        }
        return memo[mask] = ways;
    }
};