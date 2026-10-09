class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:

        freqs = Counter(tasks)
        
        h = [-v for v in freqs.values()]

        heapq.heapify(h)
        time = 0
        q = deque()

        while h or q:
            while q and q[0][0] <= time:
                heapq.heappush(h, q.popleft()[1])

            if h:
                cur = heapq.heappop(h)
                cur += 1

                if cur:
                    q.append(((time + n + 1), cur))
            
            if q and not h:
                time = max(time + 1, q[0][0])
            else:
                time += 1
            
        return time

                
            

                




