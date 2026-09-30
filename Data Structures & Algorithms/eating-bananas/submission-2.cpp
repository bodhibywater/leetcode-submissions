class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int m = l + (r - l) / 2;

            long long t = 0;
            for (int pile : piles) {
                t += ceil(static_cast<double>(pile) / m);
            }

            if (t <= h) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
