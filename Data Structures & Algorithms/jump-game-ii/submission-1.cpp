class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int jumps = 0;
        while (r < nums.size() - 1) {
            int maxJump = 0;
            for (int i = l; i <= r; i++) {
                maxJump = max(maxJump, i + nums[i]);
            }
            l = r;
            r = maxJump;
            jumps++;
        }
        return jumps;
    }
};
