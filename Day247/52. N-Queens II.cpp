class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        function<void(int, int, int, int)> backtrack =
            [&](int row, int cols, int leftDiag, int rightDiag) {
                if (row == n) {
                    count++;
                    return;
                }
                int availablePositions =
                    ((1 << n) - 1) & ~(cols | leftDiag | rightDiag);
                while (availablePositions) {
                    int pos = availablePositions & -availablePositions;
                    availablePositions -= pos;
                    backtrack(row + 1, cols | pos, (leftDiag | pos) << 1,
                              (rightDiag | pos) >> 1);
                }
            };
        backtrack(0, 0, 0, 0);
        return count;
    }
};