/*
We are given array of prices of neetcoin
We can only own one Neetcoin at a time
If we sell, we cannot buy the next day

At each day, we can:
- can buy only if we haven't already bought (profit - prices[i])
- sell if we own (profit + prices[i])

For cooldown we can just inc i by 2

Should also use memoisation
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int buying = 1; buying >= 0; buying--) {
                if (buying) {
                    int buy = dp[i+1][0] - prices[i];
                    int cooldown = dp[i+1][1];
                    dp[i][1] = max(buy, cooldown);
                } else {
                    int sell = (i + 2 < prices.size()) ? dp[i+2][1] + prices[i] : prices[i];
                    int cooldown = dp[i+1][0];
                    dp[i][0] = max(sell, cooldown);
                }
            }
        }
        return dp[0][1];
    }
};

class SolutionMemo {
public:
    vector<vector<int>> memo;
    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size(), vector<int>(2, -1)); // index 0 is selling, index 1 is buying
        return dp(prices, 0, true);
    }
private:
    int dp(vector<int>& prices, int i, bool canBuy) {
        if (i >= prices.size()) {
            return 0;
        }
        if (memo[i][canBuy] != -1) {
            return memo[i][canBuy];
        }

        int noBuy = dp(prices, i + 1, canBuy);
        if (canBuy) {
            int buy = dp(prices, i + 1, false) - prices[i];
            return memo[i][true] = max(noBuy, buy);
        } else {
            int sell = dp(prices, i + 2, true) + prices[i];
            return memo[i][false] = max(noBuy, sell);
        }
    }
};
