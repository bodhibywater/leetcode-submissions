/*
We should iterate through the letters in the shortest string and for each 
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> table(text1.size() + 1, vector<int>(text2.size() + 1));

        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    table[i][j] = 1 + table[i+1][j+1];
                } else {
                    table[i][j] = max(table[i+1][j], table[i][j+1]);
                }
            }
        }
        return table[0][0];
    }
};

class SolutionRec {
    vector<vector<int>> memo;
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
        return dp(text1, text2, 0, 0);
    }
private:
    int dp(string& text1, string& text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (text1[i] == text2[j]) {
            return memo[i][j] = (1 + dp(text1, text2, i + 1, j + 1));
        } else {
            return memo[i][j] = max(dp(text1, text2, i + 1, j), dp(text1, text2, i, j + 1));
        }
    }
};

