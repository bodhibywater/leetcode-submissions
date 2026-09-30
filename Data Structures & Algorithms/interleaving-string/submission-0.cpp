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
