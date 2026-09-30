class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sub;
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
        while (candidates[i] == candidates[i+1]) {
            i++;
        }
        backtrack(candidates, i + 1, target, sub);
    }
};
