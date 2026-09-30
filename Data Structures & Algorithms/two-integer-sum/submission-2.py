class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numSet = {}

        for i in range(len(nums)):
            numSet[nums[i]] = i
        
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in numSet and numSet[diff] != i:
                return [i, numSet[diff]]
        
        return []