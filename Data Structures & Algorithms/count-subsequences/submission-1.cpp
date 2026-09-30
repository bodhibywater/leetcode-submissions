/*
We should use dynamic programming, with index of s and length of curSub

At each index i of s, we can either:
- take current char iff s[i] == t[curLen]
- or skip current char and move to i+1

table[0][0] = 1;
table[i][j] = table[i+1][j] +? table[i+1][j+1]

table[i][j] = table[i-1][j] (if t[j] == s[i]) + table[i-1][j-1]
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> table(s.size() + 1, vector<int>(t.size() + 1, 0));
        
        for (int i = 0; i <= s.size(); i++) {
            table[i][t.size()] = 1;
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = t.size() - 1; j >= 0; j--) {
                table[i][j] += table[i+1][j];
                if (s[i] == t[j]) {
                    table[i][j] += table[i+1][j+1];
                } 
            }
        }
        return table[0][0];
    }
};

class SolutionMemo {
    vector<vector<int>> memo;
public:
    int numDistinct(string s, string t) {
        memo.resize(s.size(), vector<int>(t.size(), -1));
        return dp(s, t, 0, 0);
    }
private:
    int dp(string& s, string&t, int i, int curLen) {
        if (curLen >= t.size()) return 1;
        if (i >= s.size()) return 0;

        if (memo[i][curLen] != -1) {
            return memo[i][curLen];
        }
        if (s[i] == t[curLen]) {
            return memo[i][curLen] = dp(s, t, i + 1, curLen + 1) + dp(s, t, i + 1, curLen);
        } else {
            return memo[i][curLen] = dp(s, t, i + 1, curLen);
        }
    }
};
