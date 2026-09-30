class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub;
        backtrack(nums, 0, target, sub);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int i, int target, vector<int> sub) {
        // subtract every nums[i] added from target, when target == 0, return
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }

        sub.push_back(nums[i]);
        backtrack(nums, i, target - nums[i], sub);
        sub.pop_back();
        backtrack(nums, i+1, target, sub);
    }
};
