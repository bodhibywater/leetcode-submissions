class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # use a max heap and pop when len(h) > k?
        h = [(-(x*x + y*y), (x, y)) for x, y in points]
        heapq.heapify(h)
        while len(h) > k:
            heapq.heappop(h)
        
        res = []
        while len(h):
            dist, (x, y) = heapq.heappop(h)
            res.append([x, y])
        return res