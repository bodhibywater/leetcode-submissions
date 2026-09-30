class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //prices[i] is priceon the ith day
        //can buy on any day and sell any day in future
        //return max profit

        //make each index point to a vector of profits
        int l = 0;
        int r = 1;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
