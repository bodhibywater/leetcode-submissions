class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> taken(nums.size(), false);
        backtrack(nums, cur, taken);
        return res;
    }
private:
    void backtrack(vector<int>& nums, vector<int> cur, vector<bool>& taken) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!taken[i]) {
                cur.push_back(nums[i]);
                taken[i] = true;
                backtrack(nums, cur, taken);
                cur.pop_back();
                taken[i] = false;
            }
        }
    }
};
