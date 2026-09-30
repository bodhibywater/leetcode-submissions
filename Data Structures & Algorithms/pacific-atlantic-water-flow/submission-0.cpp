/*island is rectangular
Water can flow from a cell to a cell of equal or adjacent height
We need to return cells where water can reach both oceans from it

We should run a DFS from all cells bordering an ocean, and add them to two hashsets, pacific and 
atlantic. The cells that are in both should be push_back() to the res vector.

*/
class Solution {
    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, heights[0].size() - 1);
        }
        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, heights.size() - 1, i);
        }
        // now all we need to do is return the intersection of pacific and atlantic
        // whats the quickest way to do this other then just iterating through both??

        for (int r = 0; r < heights.size(); ++r) {
            for (int c = 0; c < heights[0].size(); ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c) {
        if (r < 0 || r >= heights.size() || c < 0 || 
            c >= heights[0].size() || ocean[r][c]) {
            return;
        }
        ocean[r][c] = true;
        
        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size()) continue;
            if (heights[nr][nc] >= heights[r][c]) dfs(heights, ocean, nr, nc);
        }
    }
};
