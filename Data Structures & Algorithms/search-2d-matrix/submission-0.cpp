class Solution {
public:
    bool searchRow(vector<int>& row, int target) {
        int l = 0, r = row.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (target < row[m]) {
                r = m - 1;
                continue;
            } else if (target > row[m]) {
                l = m + 1;
                continue;
            } else {
                return true;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // create helper function that b-searches a row
        // in this func, compare target with last elem of every row to locate row to search
        // if (target > last int in row) then call helper on that row

        int l = 0, r = matrix.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (target < matrix[m][0]) {
                r = m - 1;
                continue;
            } else if (target > matrix[m][matrix[0].size() - 1]) {
                l = m + 1;
                continue;
            } else {
                break;
            }
        }
        return searchRow(matrix[(l + r) / 2], target);
    }
};
