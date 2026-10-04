class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0
        freqs = {}
        maxF = 0
        l = 0

        for r in range(len(s)):
            freqs[s[r]] = 1 + freqs.get(s[r], 0)
            maxF = max(maxF, freqs[s[r]])#

            while (r - l + 1) - maxF > k:
                freqs[s[l]] -= 1
                l += 1
            res = max(res, r - l + 1)

        return res



        