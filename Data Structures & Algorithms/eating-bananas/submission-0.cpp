class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;
        while (l <= r) {
            int m = (l + r) / 2;

            long long totalTime = 0;
            for (int pile : piles) {
                totalTime += ceil(static_cast<double>(pile) / m);
            }
            if (totalTime <= h) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
