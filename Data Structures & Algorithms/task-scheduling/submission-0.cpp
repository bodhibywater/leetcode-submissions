class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // use frequency list to store f of tasks:
        vector<int> freq(26, 0);
        // use maxHeap to have quick access to most frequent task
        priority_queue<int> maxHeap;
        // use priority queue to store when tasks are next available
        queue<pair<int, int>> q;
        // store like this {time, task}, pretty sure this will store baed on the time value

        // populating frequenct list:
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // populating maxHeap:
        for (int f : freq) {
            if (f > 0) {
                maxHeap.push(f);
            }
        }

        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cur = maxHeap.top() - 1;
                maxHeap.pop();
                if (cur > 0) {
                    q.push({cur, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
