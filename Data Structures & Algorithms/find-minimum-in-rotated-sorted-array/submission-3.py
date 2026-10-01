class Solution:
    def findMin(self, nums: List[int]) -> int:
        # We can split the array into two sorted segments
        # max min val wil be min(a[0], b[0])
        # we can binary search to find segment split pos
        # at all times two of l, m, r will be in the same segment, so we set l/r to m+1/m-1 
        # depending on which seg m is in?? or something like this
        # we need to find a rule that determines which seg m is in
        # I guess m is either bigger then both l and r or smaller then both as it must be closer to split?

        l, r = 0, len(nums) - 1
        res = nums[0]

        while l <= r:
            if (nums[l] < nums[r]):
                res = min(nums[l], res)
                break
            m = (l + r) // 2
            res = min(res, nums[m])

            if nums[l] <= nums[m]:
                l = m + 1
            else:
                r = m -1

        return res
