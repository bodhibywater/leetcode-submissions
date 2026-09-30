class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        Sdict = defaultdict(int)
        Tdict = defaultdict(int)
        
        for a, b in zip(s, t):
            Sdict[a] += 1
            Tdict[b] += 1
        
        return Sdict == Tdict