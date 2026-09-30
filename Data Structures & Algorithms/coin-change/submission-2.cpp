class Solution {
    unordered_map<int, int> memo; // amount -> numOfCoinsFromHere
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = dp(coins, amount);
        return res == INT_MAX ? -1 : res;
    }
private:
    int dp(vector<int>& coins, int amount) {
        if (amount <= 0) {
            return 0;
        }
        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }
        int res = INT_MAX;
        for (int coin : coins) {
            if (coin <= amount) {
                int take = dp(coins, amount - coin);
                if (take != INT_MAX) {
                    res = min(res, 1 + take);
                }
            }
        }
        return memo[amount] = res;
    }
};
