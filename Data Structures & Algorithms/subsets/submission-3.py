class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        cur = []
        n = len(nums)

        def backtrack(i):
            if i >= n:
                res.append(cur.copy())
                return
            cur.append(nums[i])
            backtrack(i + 1)
            cur.pop()
            backtrack(i + 1)

        backtrack(0)
        return res


