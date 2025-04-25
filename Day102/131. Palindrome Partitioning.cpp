class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        
        vector<vector<string>> result;
        vector<string> current;
        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                result.push_back(current);
                return;
            }
            for (int end = start; end < n; ++end) {
                if (!dp[start][end]) continue;
                current.push_back(s.substr(start, end - start + 1));
                dfs(end + 1);
                current.pop_back();
            }
        };
        
        dfs(0);
        return result;
    }
};
