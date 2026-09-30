/*
For every ith char in s, if the cur digit is a 1 or 2 we can:
- take the cur num and move on
- not take the cur num and use it with the second num

Maybe we can pass once  and fill a cache with bools depending on whether from index i
we can move on or not???

This could work and then we could do some summing shit to find total num of ways to decode
Questions hints at this sort of thing as we dont need to return decoded solutions

Maybe could even do one pass and increment some counter
Something like this:

for (int i = 0; i < s.size(); i++) {
    counter++;
    if (s[i] == 1 || s[i] == 2 &&  s[i+1] <= 6) {
        counter++;
    }
}
we can set a flag if cur char was used by the last char, if we encounter a 0 and this flag isnt set
we should return 0!!
Otherwise we should continue
_____________________________________________________________________________________________
Im acc just gonna for a top-down approach for now and then optimise, I think this is always the 
better approach tbh, as the O(1) solution is generally trivially derived from the recurrence 
relation. 

Basically think in terms of top-down first then progress to optimising. In an interview setting
this is much better aswell as atleast u can probs get something working.

So recurence relation is:

dfs(i) = dfs(i+1) + dfs(i+2, with conditions)

dfs(i, with conditions) = dfs(i-1) + dfs(i-2)

*/

class Solution {
public:
    int numDecodings(string s) {
        // essentially we are trying to do the same thing without the vector
        int cur = 0;
        int prev1 = 1, prev2 = 0;

        for (int i = s.size(); i >= 0; i--) {

            if (s[i] == '0') {
                cur = 0;
            } else {
                cur = prev1;
                if (i + 1 < s.size() && (s[i] == '1' ||
                    s[i] == '2' && s[i + 1] < '7')) {
                        cur += prev2;
                }
            }
            prev2 = prev1;
            prev1 = cur;
            cur = 0;
        }
        return prev1;
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size());
        dp[s.size()] = 1;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < s.size() && (s[i] == '1' ||
                    s[i] == '2' && s[i + 1] < '7')) {
                        dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }
};

class Solution3 {
public:
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }
private:
    int dfs(string s, int i, unordered_map<int, int>& dp) {
        if (dp.count(i)) {
            return dp[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, i + 1, dp);
        if (i + 1 < s.size() && (s[i] == '1' ||
            s[i] == '2' && s[i + 1] < '7')) {
            res += dfs(s, i + 2, dp);
        }
        dp[i] = res;
        return res;
    }
};
