class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        countS = defaultdict(int)
        countT = defaultdict(int)

        for sc, tc in zip(s, t):
            countS[sc] += 1
            countT[tc] += 1
        
        return countS == countT
        