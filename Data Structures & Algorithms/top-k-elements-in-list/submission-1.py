class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = [[] for i in range(len(nums) + 1)]

        countMap = defaultdict(int)

        for n in nums:
            countMap[n] += 1
        
        for n, c in countMap.items():
            counts[c].append(n)

        res = []

        for i in range(len(counts) - 1, 0, -1):
            for n in counts[i]:
                res.append(n)
                if len(res) == k:
                    return res
        
            
