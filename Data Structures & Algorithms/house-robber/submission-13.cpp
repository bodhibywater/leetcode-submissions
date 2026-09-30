/*
We'll make somre dp function where dp(i) means amount of money we can steal from i..end

memo[i] = max(dp(nums, i + 1, cur), dp(nums, i + 2, cur + nums[i]))
*/
// we start from 0
// tab[0] = nums[0];
// tab[1] = max(nums[0], nums[1])
// tab[i] = max(tab[i-1], nums[i] + tab[i-2])

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int num : nums) {
            int cur = max(rob2 + num, rob1);
            rob2 = rob1;
            rob1 = cur;
        }
        return rob1;
    }
};

class SolutionTab {
public:
    int rob(vector<int>& nums) {
        vector<int> tab(nums.size());
        tab[0] = nums[0];
        tab[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            tab[i] = max(tab[i-1], nums[i] + tab[i-2]);
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
