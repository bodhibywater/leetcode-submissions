class Solution {
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = row + directions[i][0];
                int c = col + directions[i][1];

                if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != INT_MAX) {
                    continue;
                }
                grid[r][c] = 1 + grid[row][col];

                q.push({r, c});
            }
        }
        return;
    }
};
