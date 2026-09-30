class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // binary search on start_i to find left and right interval that newInterval falls between
        // then check for overlap and merge if needed

        int l = 0, r = intervals.size() - 1;

        while (l <= r) {
            int m = (r + l) / 2;

            if (intervals[m][0] < newInterval[0]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // so when we exit this, l will point at intersection above target, r will point at
        // intersection below target

        // [0, 1, 2, 3, 4, 5]. If we insert here at 2 we get
        // [0, 1, X, 2, 3, 4, 5], so we should insert at intervals.size() + l;

        intervals.insert(intervals.begin() + l, newInterval);

        vector<vector<int>> res;

        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};
