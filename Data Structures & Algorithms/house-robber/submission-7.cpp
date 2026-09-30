/*
At the ith house, we can either:
- steal from the house and move to the i + 2nd house
- or skip the house and move to the i + 1th house

We should use memoisation, to track max amount we can rob from house i.

memo[i] = max(dp(nums, cur, i + 1), dp(nums, cur + nums[i], i + 2))
*/
class Solution {
    public:
    int rob(vector<int>&nums) {
        vector<int> tab(nums.size());
        tab[0] = nums[0];
        tab[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++) {
            tab[i] = max(nums[i] + tab[i-2], tab[i - 1]);
        }
        return tab[nums.size() - 1];
    }
};

class SolutionMemo {
    vector<int> memo;
public:
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dp(nums, 0);
    }
private:
    int dp(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        return memo[i] = max(dp(nums, i + 1), nums[i] + dp(nums, i + 2));
    }
};
