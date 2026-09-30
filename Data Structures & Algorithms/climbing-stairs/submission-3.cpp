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
// We want num ways to reach end, at ith step we can either:
// - take 1 step, and move to i+1th stair
// - or take 2 steps, and move to i+2nd stair
// we want to cache the num of ways to reach final stair from each stair to avoid recomputing shit
// then we can just return memo[0]

class Solution {
    vector<int> memo;
public:
    int climbStairs(int n) {
        memo.resize(n, -1);
        return numWaysToClimbStairs(n, 0);
    }
private:
    int numWaysToClimbStairs(int n, int i) {
        if (i >= n) {
            return i == n; // as this means we have found a way
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = numWaysToClimbStairs(n, i + 1) + numWaysToClimbStairs(n, i + 2);

        return memo[i];
    }
};
