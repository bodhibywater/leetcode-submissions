/*
We'll make somre dp function where dp(i) means amount of money we can steal from i..end

memo[i] = max(dp(nums, i + 1, cur), dp(nums, i + 2, cur + nums[i]))
*/
class Solution {
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
