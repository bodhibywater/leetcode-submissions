/*
Given int n which is height of staircase

At any point, you can climb 1 or 2 steps

Return how many *distinct* ways to climb the staircase.


Recursion relation:

We are at the ith step, we can either:

- Take 1 step, moving to the i+1th step.

- take 2 steps, moving to the i+2th step. (Only if i+2 <= n)

End recursion when i == n.

We will pass a &counter, i and n into the recursive function.

when n = 1, res = 1
when n = 2, res = 2
when n = 3, res = 3
when n = 4, res = 5

*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
