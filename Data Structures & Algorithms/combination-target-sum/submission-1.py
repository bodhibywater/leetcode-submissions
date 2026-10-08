class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        cur = []
        
        def dfs(i, cursum):
            if cursum == target:
                res.append(cur.copy())
                return
            if i >= len(nums) or cursum > target:
                return
            
            cur.append(nums[i])
            dfs(i, cursum + nums[i])
            cur.pop()
            dfs(i + 1, cursum)
        
        dfs(0, 0)
        return res