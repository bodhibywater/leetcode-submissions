/*
We should iterate through word1.
At each index, we check if word1[i] == word2[i], if it does we move on
If not we can perform all three operations and go on from there.
When inserting or changing we should use * which acts like a wildcard
We can also memo based on index i (through word2) and a hash_map for curState of word1

*/
class Solution {
    vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        memo.resize(word1.size(), vector<int>(word2.size(), -1));
        return dp(word1, word2, 0, 0);
    }
private:
    int dp(string& word1, string& word2, int i, int j) {
        if (i >= word1.size()) return word2.size() - j;
        if (j >= word2.size()) return word1.size() - i;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (word1[i] == word2[j]) {
            return memo[i][j] = dp(word1, word2, i + 1, j + 1);
        } else {
            return memo[i][j] = min(min(dp(word1, word2, i + 1, j + 1), 
                        dp(word1, word2, i, j + 1)), dp(word1, word2, i + 1, j)) + 1;
        }
    }
};
