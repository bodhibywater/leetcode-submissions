// one would think greedy
// we can sort descending and then try from top untill we make target
// could also add to hashset and check for target-sigma until target gets below 0
// or some shit but this doesnt 

/*
Base conditions:
- we should stop recursion if amount <= 0
- if amount = 0 return 0
- if amount less then 0?? I guess we kill ourselves? or can just return INT_MAX maybe??

At each coin, we can either take it or not

*/
class Solution {
    unordered_map<int, int> memo;
public:
    int coinChange(vector<int>& coins, int amount) {
        // we add min from dif amounts to the hashmap as we go
        int minCoins = dp(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;

    }

private:
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int res = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                int result = dp(coins, amount - coin);
                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }
        memo[amount] = res;
        return res;
    }
};
