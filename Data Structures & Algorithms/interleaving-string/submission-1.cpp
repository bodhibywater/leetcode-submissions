/*
We need to track num of substrings for each s1 and s2 explicitly, and the dif
between these counts must be <= 1.

We can use three pointers, i, and k, to track where we are in s1, s2 and s3 respectively.

At ith char of s3, we inc two of the three pointers depending on whether:
- the kth char of s3 matches the ith or jth char of s1/s2
- if k goes out of bounds we return true
- also dont need to track k as it can be calculated bty (i + j)

also use memoisation at first, then progress to tabulation then try and optimise space

*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1= s1.size(), l2 = s2.size();
        if (s3.size() != l1 + l2) return false;
        if (l2 < l1) {
            swap(s1, s2);
            swap(l1, l2);
        }

        vector<bool> dp(l2 + 1);
        dp[l2] = true;

        for (int i = l1; i >= 0; i--) {
            vector<bool> nextDp(l2 + 1);
            if (i == l1) nextDp[l2] = true;
            for (int j = l2; j >= 0; j--) {
                if (i < l1 && s3[i + j] == s1[i] && dp[j]) {
                    nextDp[j] = true;
                }
                if (j < l2 && s3[i + j] == s2[j] && nextDp[j + 1]) {
                    nextDp[j] = true;
                }
            }
            dp = nextDp;
        }
        return dp[0];
    }
};


class SolutionTable {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1= s1.size(), l2 = s2.size();
        if (s3.size() != l1 + l2) return false;

        vector<vector<bool>> table(l1 + 1, vector<bool>(l2 + 1, false));
        table[l1][l2] = true;

        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                if (s3[i + j] == s1[i] && table[i + 1][j]) {
                    table[i][j] = true;
                }
                if (s3[i + j] == s2[j] && table[i][j + 1]) {
                    table[i][j] = true;
                }
            }
        }
        return table[0][0];
    }
};

class SolutionMemo {
    vector<vector<int>> memo;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size();
        if (s3.size() != l1 + l2) return false;
        memo.resize(l1 + 1, vector<int>(l2 + 1, -1));
        return dp(s1, s2, s3, 0, 0);
    }
private:
    bool dp(string& s1, string& s2, string& s3, int i, int j) {
        if (i + j >= s3.size()) {
            return (i == s1.size()) && (j == s2.size());
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        bool res = false;
        if (i < s1.size() && s3[i + j] == s1[i]) {
            res = dp(s1, s2, s3, i + 1, j);
        }
        if (j < s2.size() && s3[i + j] == s2[j]) {
            res = dp(s1, s2, s3, i, j + 1);
        }
        return memo[i][j] = res;
    }
};
