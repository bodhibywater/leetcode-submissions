class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;

        for (size_t i = 0; i < nums.size(); ++i) {
            indices[nums[i]] = i;
        }

        for (int i = 0; const auto num : nums) {
            int diff = target - nums[i];
            auto it = indices.find(diff);
            if (it != indices.end() && it->second != i) {
                return {i, it->second};
            }
            i++;
        }
        return {};
    }
};
