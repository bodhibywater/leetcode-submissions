class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, sub);
        return res;
    }
private:
    void backtrack(vector<int>& nums, int i, vector<int>& sub) {
        if (i >= nums.size()) {
            res.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        backtrack(nums, i + 1, sub);
        sub.pop_back();
        while (nums[i] == nums[i+1]) i++;
        backtrack(nums, i + 1, sub);
    }
};
