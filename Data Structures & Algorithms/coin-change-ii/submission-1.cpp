/*
At the ith coin in coins, we can either:
- take the coin -> amount - coin[i]
- no take the coin -> i+1

and obvs memo

*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        // there is 1 way to make amount = 0 from any index i, so we should build from there

        for (int i = 0; i <= coins.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int a = 0; a <= amount; a++) {
                if (a >= coins[i]) {
                    dp[i][a] = dp[i][a - coins[i]] + dp[i+1][a];
                }
            }
        }
        return dp[0][amount];
    }
};


class SolutionMemo {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        memo.resize(coins.size(), vector<int>(amount + 1, -1));
        return dp(coins, amount, 0);
    }
private:
    int dp(vector<int>& coins, int amount, int i) {
        if (amount == 0) {
            return 1;
        }
        if (i >= coins.size() || amount < 0) {
            return 0;
        }
        if (memo[i][amount] != -1) {
            return memo[i][amount];
        }

        memo[i][amount] = dp(coins, amount - coins[i], i) + dp(coins, amount, i + 1);

        return memo[i][amount];
    }
};
