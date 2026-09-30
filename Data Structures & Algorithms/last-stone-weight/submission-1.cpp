class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // we want to use a maxheap, then get the first two elems and run the simulation
        // iteratively

        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (y < x) {
                maxHeap.push(x - y);
            }
        }
        
        maxHeap.push(0); // niche
        return maxHeap.top();
    }
};
