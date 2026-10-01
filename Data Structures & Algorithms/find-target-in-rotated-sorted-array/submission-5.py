class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # can split into two sorted arrays
        # we can find the split using b-search
        # then b-search over sub-array containing target?? 
        # should be O(logn) time O(1) space

        l, r = 0, len(nums) - 1
        
        splitId = 0

        while l < r:
            if nums[l] < nums[r]:
                if nums[l] < nums[splitId]:
                    splitId = l
                break

            m = (l + r) // 2
            if nums[m] < nums[splitId]:
                splitId = m
            
            if nums[l] <= nums[m]:
                l = m + 1
            else:
                r = m - 1
        
        if nums[l] < nums[splitId]:
            splitId = l

        # check if target in l..splitId or splitId..r
        if target <= nums[-1]:
            l, r = splitId, len(nums) - 1
        else:
            l, r = 0, splitId - 1

        while l <= r:
            m = (l + r) // 2
            if target < nums[m]:
                r = m - 1
            elif target > nums[m]:
                l = m + 1
            else:
                return m
        return -1