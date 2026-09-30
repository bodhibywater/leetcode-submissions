/*
We can start at any square in the matrix, at each we can move any direction where newNum > num
We should use memoisation, 2D vector, to store integer result starting from each square to avoid
recomputing stuff
We cant revisit cells, this can be covered by using a hashset, or only going to a cell if newNum
is strictly bigger then curNum


*/
class Solution {
    vector<vector<int>> memo;
    vector<vector<int>> directions = {{-1, 0}, {1, 0},
                                      {0, -1}, {0, 1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memo.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                res = max(res, dp(matrix, i, j));
            }
        }
        return res;
    }
private:
    int dp(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int res = 1;
        for (auto& d : directions) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || ni >= matrix.size() || nj < 0 || nj >= matrix[0].size()) continue;
            if (matrix[ni][nj] > matrix[i][j]) {
                res = max(res, 1 + dp(matrix, ni, nj));
            }
        }
        return memo[i][j] = res;
    }
};
