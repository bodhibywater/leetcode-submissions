class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # clearly we use max heap, at each step pop 2 and run experiment
        # exit when len(h) <= 1 then return h[0] or 0
        h = [-x for x in stones]
        heapq.heapify(h)

        while len(h) > 1:
            a = heapq.heappop(h)
            b = heapq.heappop(h)
            if a < b:
                heapq.heappush(h, a - b)
            elif b < a:
                heapq.heappush(h, b - a)
        
        return -h[0] if len(h) else 0


            