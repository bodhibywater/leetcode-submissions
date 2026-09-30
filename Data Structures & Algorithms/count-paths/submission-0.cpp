/*
m x n grid where we are allowed to move down or to the right only

Return the nuber os unique paths that can be taken from the top left corner to the
bottom right corner

At every square (i,j), we can either:
- move down to (i+1, j)
- or move right to (i, j+1)

We should use memoisation to store number of unique paths from each square (can use 2D vector)

memo[i][j] = dp(m, n, i + 1, j) + dp(m, n, i, j + 1)

*/
class Solution {
    vector<vector<int>> memo;
public:
    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        return dp(m, n, 0, 0);
    }
private:
    int dp(int m, int n, int i, int j) {
        if (i == (m - 1) && j == (n - 1)) {
            return 1;
        }
        if (i >= m || j >= n) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        } 

        memo[i][j] = dp(m, n, i + 1, j) + dp(m, n, i, j + 1);

        return memo[i][j];
    }
};
