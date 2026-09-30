class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hset;
        int res = 0;

        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            while (hset.count(s[r])) {
                hset.erase(s[l]);
                l++;
            }
            hset.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
