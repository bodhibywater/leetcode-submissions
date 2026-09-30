/*
m x n grid where we are allowed to move down or to the right only

Return the nuber os unique paths that can be taken from the top left corner to the
bottom right corner

At every square (i,j), we can either:
- move down to (i+1, j)
- or move right to (i, j+1)

We should use memoisation to store number of unique paths from each square (can use 2D vector)

memo[i][j] = dp(m, n, i + 1, j) + dp(m, n, i, j + 1)

Now we need to try and progress to a bottom-up solution:
So think of an inductive formula.

UP[m - 1, n - 1] = 1
UP[m - i, n - i] = UP[m - i + 1, n - i]  + UP[m - i, n - i + 1]
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m+1, vector<int>(n+1, 0));
        table[m-1][n-1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                table[i][j] += table[i + 1][j] + table[i][j + 1];
            }
        }
        return table[0][0];
    }
};
class Solution2 {
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

        return memo[i][j] = dp(m, n, i + 1, j) + dp(m, n, i, j + 1);
    }
};
