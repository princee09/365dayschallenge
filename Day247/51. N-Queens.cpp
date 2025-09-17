class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> leftDiag(2 * n - 1, false);
        vector<bool> rightDiag(2 * n - 1, false);

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                res.push_back(board);
                return;
            }
            for (int col = 0; col < n; col++) {
                int ld = row - col + n - 1;
                int rd = row + col;
                if (cols[col] || leftDiag[ld] || rightDiag[rd]) {
                    continue;
                }
                board[row][col] = 'Q';
                cols[col] = true;
                leftDiag[ld] = true;
                rightDiag[rd] = true;
                backtrack(row + 1);
                board[row][col] = '.';
                cols[col] = false;
                leftDiag[ld] = false;
                rightDiag[rd] = false;
            }
        };

        backtrack(0);
        return res;
    }
};