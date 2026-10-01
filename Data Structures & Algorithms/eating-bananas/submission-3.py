class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # return min k. 1 <= k <= max entry in piles
        l, r = 1, max(piles)
        res = r

        while l <= r:
            m = (l + r) // 2
            t = 0

            for pile in piles:
                t += -(pile // -m)
            
            if t <= h:
                res = m
                r = m - 1
            else:
                l = m + 1
        
        return res


            
