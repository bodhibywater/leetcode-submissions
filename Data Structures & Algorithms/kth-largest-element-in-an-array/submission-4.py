class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # I guess min heap?
        h = nums
        heapq.heapify(h)

        while len(h) > k:
            heapq.heappop(h)
        
        return h[0]
        
