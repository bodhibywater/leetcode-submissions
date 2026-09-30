/*
Given: array of positive ints nums
Return: bool on whether we can partition nums into two subsets where:
- sum(subset1) == sum(subset2)

So obviously, this is only possible if sum of nums is even, so ig we can do some shit here

Fiirst we should find sum of nums and return false if not even
then we can find target which is sum/2

Now all we need is a way to make target from num in nums, as remaining nums will form target aswell

So this reduces to a much easier problem.

**We need to make target (sum/2) from ints in nums.**

For every ith num in nums, we can either:
- take the cur num, and recurse with (target - num, i+1)
- or skip it and recurse with (target, i+1)

Base case:
- if target == 0, return true
- if i >= nums.size() return false

How can we use memoisation here?
*/
class Solution {
    vector<vector<int>> memo;
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;

        memo.resize(nums.size(), vector<int>(sum/2 + 1, -1));
        return dp(nums, 0, sum / 2); 
    }
private:
    bool dp(vector<int>& nums, int i, int target) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return false;
        }

        if (memo[i][target] != -1) {
            return memo[i][target];
        }

        memo[i][target] =  dp(nums, i + 1, target) ||
                           dp(nums, i + 1, target - nums[i]);
        return memo[i][target];
    }
};
