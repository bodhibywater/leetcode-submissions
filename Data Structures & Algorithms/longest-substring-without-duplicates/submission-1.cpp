class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_set<char> hset;
        int maxL = 0;
        while (r < s.size()) {
            while(hset.count(s[r])) {
                hset.erase(s[l]);
                l++;
            }
            hset.insert(s[r]);
            maxL = max(maxL, r - l + 1);
            r++;
        }
        return maxL;
    }
};
