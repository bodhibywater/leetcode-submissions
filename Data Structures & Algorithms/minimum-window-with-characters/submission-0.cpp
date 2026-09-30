/*
we need to track freqs of chars in t.

Then we can sliding window on s, and check if we have all the chars.

As we iterate through, if we dont care about char -> l++, if we do we can r++

If we find a char later on that we need but alr4eady have then we again l++.

Feels like we are going to need a few ds.

Maybe we fill two vectors with the frequencies of chars in t, one to modify and one to not
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char cur = s[r];
            window[cur]++;

            if (countT.count(cur) && window[cur] == countT[cur]) {
                have++;
            }
            while (have == need) {
                if ((r - l) + 1 < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
