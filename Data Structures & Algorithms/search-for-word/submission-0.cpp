class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> hset;

    bool exist(vector<vector<char>>& board, string word) {
        // Use backtracking, find first letter then choose each bordering letter as decision
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private: 
    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) return true;

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || hset.count({r, c})) {
                return false;
            }

        hset.insert({r, c});

        bool res = backtrack(board, word, r + 1, c, i + 1) ||
                   backtrack(board, word, r - 1, c, i + 1) ||
                   backtrack(board, word, r, c + 1, i + 1) ||
                   backtrack(board, word, r, c - 1, i + 1);
        
        hset.erase({r, c});

        return res;
    }
};
