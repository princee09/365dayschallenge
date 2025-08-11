class Solution {
public:
    int n;
    vector<vector<int>> memo;
    vector<int> suffix;

    int dfs(int i, int M) {
        if (i >= n) return 0;
        if (memo[i][M] != -1) return memo[i][M];

        int best = 0;
        for (int x = 1; x <= 2 * M && i + x <= n; ++x) {
            int next = dfs(i + x, max(M, x));
            int take = suffix[i] - next;
            best = max(best, take);
        }
        memo[i][M] = best;
        return best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) suffix[i] = suffix[i + 1] + piles[i];
        memo.assign(n, vector<int>(n + 1, -1));
        return dfs(0, 1);
    }
};
