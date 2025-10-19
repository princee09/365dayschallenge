class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowSeen[9][9] = {false};
        bool colSeen[9][9] = {false};
        bool boxSeen[9][9] = {false};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                int digit = board[i][j] - '1'; 
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (rowSeen[i][digit] || colSeen[j][digit] || boxSeen[boxIndex][digit]) {
                    return false;
                }
                rowSeen[i][digit] = true;
                colSeen[j][digit] = true;
                boxSeen[boxIndex][digit] = true;
            }
        }
        
        return true;
    }
};