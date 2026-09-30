class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // use minHeap, maintain its size to be k, then simply return top

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
