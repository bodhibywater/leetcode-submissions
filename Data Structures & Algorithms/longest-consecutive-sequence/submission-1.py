class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        res = 0
        for n in nums:
            if (n - 1) not in s:
                temp = 1
                while (n + temp) in s:
                    temp += 1
                res = max(res, temp)
        return res