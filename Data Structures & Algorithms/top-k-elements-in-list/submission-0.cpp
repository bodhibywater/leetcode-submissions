class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Return k most frequent elems from nums

        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int num : nums) {
            count[num] = count[num] + 1;
        }

        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;

        for (int i = freq.size() - 1; i > 0; i--) {
            for (int num : freq[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
