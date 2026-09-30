/*
given array of ints nums, nums[i] is amount of money ith house has

ith house is neighbour of (i-1)th and (i+1)th

We cannot rob two adjacent houses

Return maximum amount of money you can steal

Reccurence relation:
at the ith house, we can either:
- steal from the ith house and progress to the (i+2)th house
- skip this house and progress to the (i+1)th house
    -> max(nums[i] + dfs(i + 2), dfs(i + 1));

we stop when i >= nums.size(); and return 0

Can use memoisation somehow, declare vector<int> memo, resize it to (nums.size(), -1)

we set memo[i] = max(nums[i] + dfs(i + 2), dfs(i + 1))*/

class Solution2 {
    vector<int> memo;

public:
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dfs(nums, 0);
    }

private:
    int dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1));

        return memo[i];
    }
};

class Solution {
    
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (int num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return max(rob1, rob2);
    }
};
