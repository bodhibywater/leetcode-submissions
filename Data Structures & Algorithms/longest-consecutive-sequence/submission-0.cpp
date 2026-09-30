class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> store(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (store.count(num - 1)) {
                continue;
            } else {
                int newLong = 1;
                int n = num;
                while (store.count(n + 1)) {
                    newLong++;
                    n++;
                }
                longest = max(longest, newLong);
            }
        }
        return longest;
    }
};
