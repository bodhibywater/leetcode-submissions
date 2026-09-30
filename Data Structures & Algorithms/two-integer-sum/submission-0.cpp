class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int dif = target - nums[i];
            if (umap.count(dif) && umap[dif] != i) {
                return {i, umap[dif]};
            }
        }

        return {};

    }
};

//{{3, 4}, {4, 3}, {5, 2}, {6, 1}}