class Solution {
public:
    int characterReplacement(string s, int k) {
        // iterate through 
        int res = 0;
        unordered_set<char> hset(s.begin(), s.end());

        for (char c : hset) {
            int l = 0, count = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) {
                    count++;
                }
                while ((r - l + 1) - count > k) {
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
