// backtracking probs
// at each num in nums we make a decision, we either:
// - take the num and move to i+1
// - or dont take it and move to i+1


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, 0, subset, res);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset, res);
        subset.pop_back();
        backtrack(nums, i + 1, subset, res);
    }
};
