// two poiners, both start at 0, progress r untill we hit a height bigger then l
// then set l = r, and repeat.
// whilst we inc r, we should track total area of water so far
/*
Example: height = [0,2,0,3,1,0,1,3,2,1]
- we start with l,r = 0 and do r++;
- we reach a heights bigger then what l points to, so we do l = r;
- then r++, r points at 0, so we should add (heights[l] - heights[r]) to the buffer
- the buffer is important, every time we reach a heights where we move l, we add the buffer to res
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
