/*
Dynamic Programming by the looks of it

Recurrence relation: res = max(res, dp(nums, i, j + 1)) or some shit

As we go through we can store maxNeg and maxPos, then inc i everytime we see which is bigger 
maxPos, maxNeg or nums[i#]


*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp , num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};
