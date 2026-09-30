class Solution {
    priority_queue<pair<int, int>> pq;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        vector<int> res;

        for (int i = 0; i < k - 1; i++) {
            pq.push({nums[i], i}); // O(nlogn)
        }

        for (int r = k - 1; r < nums.size(); r++) {
            pq.push({nums[r], r});
            while (pq.top().second < l) {
                pq.pop();
            }
            res.push_back(pq.top().first);
            l++;
        }
        return res;
    }
};
