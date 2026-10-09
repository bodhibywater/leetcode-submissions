class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # use a max heap and pop when len(h) > k?
        h = []

        for x, y in points:
            heapq.heappush(h, (-(x*x + y*y), (x, y)))

            if len(h) > k:
                heapq.heappop(h)
        
        return [list(point) for dist, point in h]