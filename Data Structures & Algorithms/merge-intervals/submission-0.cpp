class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Easy solution:
        // - sort intervals by start_i
        // - then create a res vector
        // - iterate through intervals (for(const auto& interval : intervals)) 
        //      and add them into res and check for overlaps, merge when necesary
        
        // It looks like there is some cool approach where you write ur own sorting algo
        // and merge as you sort
        // like a merge sort type thing, but you do additional check at each merge???

        sort(intervals.begin(), intervals.end());

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
