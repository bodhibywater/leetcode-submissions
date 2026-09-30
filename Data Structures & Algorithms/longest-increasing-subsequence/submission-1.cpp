/*
We need to return largest strictly increasing subsequence from array of ints nums

For every ith int in nums we make a decision, we either:
- skip this num and move onto i+1
- take this num and move onto i+1 (iff it is larger then last num added to the stack)

I guess we can use a stack or someshit??
this is a backtracking approach, how can we utilise memoisation????


*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);

        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
};