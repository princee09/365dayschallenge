class Solution {
public:
    double soupServings(int n) {
        if (n == 0)
            return 0.5;
        int N = (n + 24) / 25;
        if (N >= 200)
            return 1.0;

        vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1.0));
        function<double(int, int)> dp = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0)
                return 0.5;
            if (a <= 0)
                return 1.0;
            if (b <= 0)
                return 0.0;
            if (memo[a][b] >= 0)
                return memo[a][b];

            double res = 0.0;
            res += dp(a - 4, b);     // 100 A, 0 B
            res += dp(a - 3, b - 1); // 75 A, 25 B
            res += dp(a - 2, b - 2); // 50 A, 50 B
            res += dp(a - 1, b - 3); // 25 A, 75 B
            res *= 0.25;

            memo[a][b] = res;
            return res;
        };

        return dp(N, N);
    }
};