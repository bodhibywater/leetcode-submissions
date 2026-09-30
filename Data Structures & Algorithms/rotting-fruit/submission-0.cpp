class Solution {
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int checkRot = 0;
        int time = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    checkRot++;
                }
            }
        }

        while (!q.empty() && checkRot > 0) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int r = row + directions[i][0];
                    int c = col + directions[i][1];

                    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != 1) {
                        continue;
                    }
                    checkRot--;
                    grid[r][c] = 2;
                    q.push({r,c});
                }
            }
            time++;
        }

        if (checkRot == 0) {
            return time;
        } else {
            return -1;
        }
    }
};
