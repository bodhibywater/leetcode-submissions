/*
We need to return largest strictly increasing subsequence from array of ints nums

For every ith int in nums we make a decision, we either:
- skip this num and move onto i+1
- take this num and move onto i+1 (iff it is larger then last num added to the stack)

I guess we can use a stack or someshit??
this is a backtracking approach, how can we utilise memoisation????


*/
class Solution {
public:
    vector<int> memo;
    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        int maxLIS = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxLIS = max(maxLIS, dp(nums, i));
        }
        return maxLIS;
    }
private:
    int dp(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;

        if (memo[i] != -1) {
            return memo[i];
        }

        int LIS = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) {
                LIS = max(LIS, 1 + dp(nums, j));
            }
        }
        return memo[i] = LIS;
    }
};// This is O(n^2) as both i and j go into the recursive call and are n big
// Can we optimise this?
