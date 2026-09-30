class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, sub);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, int i, int target, vector<int>& sub) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (target < 0 || i >= candidates.size()) {
            return;
        }
        sub.push_back(candidates[i]);
        backtrack(candidates, i + 1, target - candidates[i], sub);
        sub.pop_back();
        while (candidates[i] == candidates[i+1]) i++;
        backtrack(candidates, i + 1, target, sub); // ***

        // need to add another condition to stop duplicates, maybe hashset or something??
        // no hashset, sort array and instead of i+1, skip all duplicate elements
        // I am  referenecing this line here ***
    }
};
