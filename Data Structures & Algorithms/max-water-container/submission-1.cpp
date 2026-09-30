class Solution {
public:
    int maxArea(vector<int>& heights) {
        // two pointer

        int l = 0, r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            int cur = (r - l) * min(heights[l], heights[r]);
            res = max(res, cur);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
