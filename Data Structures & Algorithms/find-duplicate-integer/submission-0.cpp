class Solution {
public:
    int findDuplicateNaive(vector<int>& nums) {
        unordered_set<int> hset;

        for (int n : nums) {
            if (hset.count(n)) return n;
            hset.insert(n);
        }
    }
    int findDuplicate(vector<int>& nums) {
        for (int n : nums) {
            int id = abs(n) - 1;
            if (nums[id] < 0) {
                return abs(n);
            }
            nums[id] *= -1;
        }
        return -1;
    }
};
