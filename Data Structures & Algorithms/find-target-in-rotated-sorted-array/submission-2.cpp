class Solution {
public:
    int bSearch(vector<int>&nums, int target, int l, int r) {
        while (l<=r) {
            int m = (l+r) / 2;
            if (target < nums[m]) {
                r = m -1;
            } else if (target > nums[m]) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l<r) {
            int m = (l+r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int pivot = l;

        int ret = bSearch(nums, target, 0, pivot - 1);
        if (ret != -1) {
            return ret;
        }
        return bSearch(nums, target, pivot, nums.size() - 1);
    }
};
