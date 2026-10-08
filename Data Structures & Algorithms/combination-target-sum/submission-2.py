class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        
        def dfs(i, cur, cursum):
            if cursum == target:
                res.append(cur.copy())
                return
            
            for j in range(i, len(nums)):
                if cursum + nums[j] > target:
                    return
                cur.append(nums[j])
                dfs(j, cur, cursum + nums[j])
                cur.pop()
        
        dfs(0, [], 0)
        return res