/*
Given int n which is height of staircase

At any point, you can climb 1 or 2 steps

Return how many *distinct* ways to climb the staircase.


Recursion relation:

We are at the ith step, we can either:

- Take 1 step, moving to the i+1th step.

- take 2 steps, moving to the i+2th step. (Only if i+2 <= n)

End recursion when i == n.

We will pass a &counter, i and n into the recursive function.*/

class Solution {
public:
    int climbStairs(int n) {
        return numWays(0, n);
    }

private:
    int numWays(int i, int n) {
        if (i == n) return 1;
        int counter = 0;

        counter += numWays(i + 1, n);

        if (i + 2 <= n) {
            counter += numWays(i + 2, n);
        }

        return counter;
    }
};
