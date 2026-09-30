class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefixes = [0] * n
        suffixes = [0] * n
        res = [0] * n

        prefixes[0] = suffixes[n-1] = 1

        for i in range(1, n):
            prefixes[i] = prefixes[i-1] * nums[i-1]

        for i in range(n - 2, -1, -1):
            suffixes[i] = suffixes[i+1] * nums[i+1]

        for i in range(n):
            res[i] = prefixes[i] * suffixes[i]

        return res