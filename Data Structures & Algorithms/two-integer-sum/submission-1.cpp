class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> uMap;

        for (int i = 0; i < n; i++) {
            int dif = target - nums[i];

            if (uMap.find(dif) != uMap.end()) { // exists
                return {uMap[dif], i};
            }
            uMap.insert({nums[i], i});
        }
        return {};
    }
};
