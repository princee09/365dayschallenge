class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        auto getCoordinates = [&](int s) -> pair<int, int> {
            int quot = (s - 1) / n;
            int rem = (s - 1) % n;
            int row = n - 1 - quot;
            int col = (quot % 2 == 0) ? rem : (n - 1 - rem);
            return {row, col};
        };

        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {square number, moves}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [s, moves] = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i) {
                int next = s + i;
                if (next > n * n) break;

                auto [r, c] = getCoordinates(next);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }

                if (!visited[next]) {
                    if (next == n * n) return moves + 1;
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};