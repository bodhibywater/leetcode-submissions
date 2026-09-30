/* 
Given array of ints nums
nums[i] is MAXIMUM length we can jump from i (so can jump less then that)

return minimum number of jumps needed to reach end of array
we can assume there is always a valid number

I think we should use some sort of two pointer thing
first we init both to zero

then make r point to the max distance that we can jump to from the cur window

then we set l = r + 1 and keep going until we hit end of nums

every time we move l we inc a counter numJumps, I think we can just return numJumps
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, numJumps = 0;

        while (r < nums.size() - 1) {
            int maxDistance = 0;
            
            for (int i = l; i <= r; i++) {
                maxDistance = max(maxDistance, i + nums[i]);
            }
            l = r + 1;
            r = maxDistance;
            numJumps++;
        }
        return numJumps;
    }
};
