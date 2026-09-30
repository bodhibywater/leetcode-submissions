class Solution {
public:
    int maxArea(vector<int>& heights) {
        // From array containing heights of pillars, return max that can be contained within them
        // Area = min(heights[l], heights[r]) * (r - l)
        // Use two pointer method and move pointer to smaller height pillar

        int res = 0;
        int l = 0, r = heights.size() - 1;

        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
