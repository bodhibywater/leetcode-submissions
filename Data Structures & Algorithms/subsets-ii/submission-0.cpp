class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(nums, cur, 0);
        return res;
    }
private:
    void backtrack(vector<int>& nums, vector<int> cur, int i) {
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums, cur, i + 1);
        cur.pop_back();
        while (nums[i] == nums[i + 1] && i < nums.size()) i++;
        backtrack(nums, cur, i + 1);
    }
};
