class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s) or t == "":
            return ""
            
        countT, window = {}, {}
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        have, need = 0, len(countT)
        resLength, res = float("infinity"), [-1, -1]

        l = 0

        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)

            if c in countT and window[c] == countT[c]:
                have += 1
            
            while have == need:
                if (r - l + 1) < resLength:
                    resLength = r - l + 1
                    res = [l, r]
                ct = s[l]
                window[ct] -= 1
                if ct in countT and window[ct] < countT[ct]:
                    have -= 1
                l += 1
        l, r = res
        return s[l: r + 1] if resLength != float("infinity") else ""
        


        