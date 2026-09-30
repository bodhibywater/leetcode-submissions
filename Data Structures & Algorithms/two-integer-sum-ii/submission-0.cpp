class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Return indices of two nums in "numbers" such that they sum to "target"
        // Array is sorted, so think of an algorithm to take advantage of this
        // Two pointer algorithm, one at start and one at end
        // If sum of two dereferenced pointers bigger then target move right pointer left one
        // else move left pointer right one

        int l = 0; int r = numbers.size() - 1;

        while (l < r) {
            if (numbers[l] + numbers[r] > target) {
                r--;
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {};
    }
};
