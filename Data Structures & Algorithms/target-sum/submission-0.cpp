/*
We are given an array of ints, nums, and an int target.

For each ith int in nums, we can either:
- add it to the total
- or sub it from the total

We need to return the number of ways to make 'target', from only the ops above

We shoul obvs use some sort of top-down memoisation recursion shit to avoid
recomputing stuff. We should make a 2D vector<vector<int>> (i, curSum)
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size() + 1); // dp[i][target]
        dp[0][0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            for (auto& p : dp[i]) {
                dp[i+1][p.first + nums[i]] += p.second;
                dp[i+1][p.first - nums[i]] += p.second;
            }
        }
        return dp[nums.size()][target];
    }
};


class SolutionMemo {
    vector<vector<int>> memo;
    int totalSum;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
       memo.resize(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
       return dp(nums, target, 0, 0); 
    }
private:
    int dp(vector<int>& nums, int target, int i, int total) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (memo[i][total + totalSum] != INT_MIN) {
            return memo[i][total + totalSum];
        }

        return memo[i][total + totalSum] = dp(nums, target, i + 1, total  - nums[i]) 
                                + dp(nums, target, i + 1, total + nums[i]);
    }
};
