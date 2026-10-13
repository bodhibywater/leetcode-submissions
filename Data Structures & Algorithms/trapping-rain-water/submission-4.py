class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n == 0:
            return 0

        prefMax = [0] * n
        suffMax = [0] * n

        prefMax[0] = height[0]

        for i in range(1, n):
            prefMax[i] = max(height[i], prefMax[i - 1])

        suffMax[n - 1] = height[n - 1]

        for i in range(n - 2, -1, -1):
            suffMax[i] = max(height[i], suffMax[i + 1])

        res = 0
        for i in range(len(height)):
            res += min(prefMax[i], suffMax[i]) - height[i]
        
        return res