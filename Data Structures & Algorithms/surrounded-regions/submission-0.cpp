/*
So any group of Os that is not connected to a border O should be turned to an X
And any O that is connected to a border O should remain an O

We should dfs from every border O and mark all Os that are connected to it with a #

Then at the end we pass through again, and turn all remaining Os to Xs and all #s to Os
*/
class Solution {
    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();

        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][COLS - 1] == 'O') dfs(board, i, COLS - 1);
        }
        for (int i = 0; i < COLS; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[ROWS - 1][i]) dfs(board, ROWS - 1, i);
        }
        // we now need all Os->Xs and all #s->Os

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int ROWS = board.size(), COLS = board[0].size();

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != 'O') {
            return;
        }
        board[r][c] = '#';
        for (auto [dr, dc] : directions) {
            dfs(board, r + dr, c + dc);
        }
    }
};
