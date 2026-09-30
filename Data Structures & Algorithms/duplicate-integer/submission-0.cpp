class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for (int num : nums) {
            if (uset.count(num)) return true;
            uset.insert(num);
        }
        return false;
    }
};