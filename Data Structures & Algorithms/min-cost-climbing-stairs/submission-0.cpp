/*
Given array of ints cost, cost[i] is the cost of taking a step from ith floor

From ith floor, we can either move to floor i+1 or i+2

We can start at index 0 or 1

We need to find minimum cost to climb the stairs

Recurrence relation:
at each step we can either:
- move one step
- move two steps

As we want the minimum cost, reccurence relation can be expressed as:
- cost[i] + min(dfs(i + 1), dfs(i + 2))

We should use memoisation to avoid recomputing shit, cache[i] should store the min cost to get
to the ith floor.
*/



class Solution {
    vector<int> memo;

public:
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

private:
    int dfs(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = cost[i] + min(dfs(cost, i + 1), dfs(cost, i + 2));

        return memo[i];
    }
};
