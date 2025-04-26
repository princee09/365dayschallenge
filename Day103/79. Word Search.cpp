class Solution {
public:
    int m, n;
    vector<vector<char>> *b;
    string w;
    // 4 possible moves: up, right, down, left
    const int di[4] = {-1, 0, 1, 0};
    const int dj[4] = {0, 1, 0, -1};

    bool dfs(int i, int j, int idx) {
        if (idx == (int)w.size()) return true;
        // boundary + match check
        if (i<0 || i>=m || j<0 || j>=n || (*b)[i][j] != w[idx]) return false;
        char save = (*b)[i][j];
        (*b)[i][j] = '#';  // mark visited
        // explore neighbours
        for (int d = 0; d < 4; d++) {
            if (dfs(i + di[d], j + dj[d], idx + 1)) {
                (*b)[i][j] = save; 
                return true;
            }
        }
        (*b)[i][j] = save;  // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); 
        n = board[0].size();
        b = &board;
        w = word;
        // 1) frequency pruning
        vector<int> freqBoard(256, 0), freqWord(256, 0);
        for (auto &row : board)
            for (char c : row)
                freqBoard[c]++;
        for (char c : word)
            freqWord[c]++;
        for (int c = 0; c < 256; c++)
            if (freqWord[c] > freqBoard[c])
                return false;

        // 2) optional: if last char rarer, reverse the word for faster mismatch
        if (freqBoard[word.back()] < freqBoard[word.front()]) {
            reverse(w.begin(), w.end());
        }

        // 3) try starting DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
