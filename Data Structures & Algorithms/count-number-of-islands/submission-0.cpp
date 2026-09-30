/*
Iterate through grid, perform dfs when we encounter a 1
Everytime we encounter a 1 we should change it to a 0 so that dont visit the same group twice

Just make a dfs helper function that returns an int and this is lowkey trivial

Should be 
*/
class Solution {
    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        for (auto& d : directions) {
            dfs(grid, i + d[0], j + d[1]);
        }
    }
};
