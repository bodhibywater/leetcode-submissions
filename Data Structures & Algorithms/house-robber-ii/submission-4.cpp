/* Same as last, but first house adjacent to last house
So we need to somehow store if we robbed the first house or not. 

If we do rob the first house, then we 

We could make somesort of subvector, where when we rob first house, we remove last house entirely

*/
// Make a 2D memoisation vector,
// also pass a flag into the vector to indicate whether you can search last house
// on case where you can, start from index 1!!!!!!!!!!

class Solution {

    vector<vector<int>> memo;

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        memo.resize(nums.size(), vector<int>(2, -1));
        return max(choose_house(nums, 0, 0), choose_house(nums, 1, 1));
    }

private:
    int choose_house(vector<int>& nums, int i, int flag) {
        if (i >= nums.size() || flag == 0 && i >= nums.size() - 1) {
            return 0;
        }

        if (memo[i][flag] != -1) {
            return memo[i][flag];
        }

        memo[i][flag] = max(nums[i] + choose_house(nums, i + 2, flag), 
                            choose_house(nums, i + 1, flag));

        return memo[i][flag];
    }
};
