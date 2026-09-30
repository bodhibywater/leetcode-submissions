class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // we track amount of gas in the car, and obvs use all the gas available at every station
        // we then subtract cost from gasCount every time we move 

        // so at every ith station, we:
        // - gasCount += gas[i]
        // - gasCount -= cost[i]
        // We return false if ever gas < 0
        
        // initial thought is some sort of dynamic programming thing with memoisation,
        // we use a memo vector and at each index i, store the furthest index that can be reached 
        // if sum(gas) < sum(cost) we return false
        // otherwise a solution must exist as there is sufficient gas

        int sumGas = accumulate(gas.begin(), gas.end(), 0);
        int sumCost = accumulate(cost.begin(), cost.end(), 0); // O(2n), delete if not necessary

        if (sumGas < sumCost) {
            return -1;
        }

        int res = 0, total = 0;

        for (int i = 0; i < gas.size() - 1; i++) {
            total += (gas[i] - cost[i]);
            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }
        return res;
    }
};
