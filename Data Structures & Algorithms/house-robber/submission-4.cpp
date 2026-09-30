/*
given array nums, where nums[i] represents amount of money in ith house
we want to find max amount of money
cant rob two adjacent houses
amount of money is always positive

at each house we make a decision:
- rob  house and move to (i + 2) house
- skip house and move to (i + 1) house

reccurence relation:
memo[i] = max(nums[i] + dp(nums, i + 2), dp(nums, i + 1));

dp(i) = max(dp(i-1), nums[i] + dp(i-2));

*/

class Solution {
    public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[nums.size() - 1];
    }
};


class Solution2 {
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

        memo[i] = max(nums[i] + dp(nums, i + 2), dp(nums, i + 1));
        return memo[i];
    }
};

