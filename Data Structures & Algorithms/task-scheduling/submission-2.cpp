/*
tasks[i] is an upercase char from 'A' to 'Z'

Each CPU cycle allows us to complete one task
We need to find the minimum number of cycles to complete all tasks

Identical tasks (when the task is same char) must be seperated by n cycles

we need some sort of frequency counter, so probs use a hashmap to count the freq of all tasks

We should start with the task that has highest frequency

Once we have done a task, we should add that char to a data structure of some sort, and track
how many more cycles we need untill we can do it again

Some sort of iterative approach
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int maxf = freq[25];

        int idle = (maxf - 1) * n; 
        // We have something like:
        // A _ _ _ A _ _ _ A _ _ _ A, idleTime = count(_)

        for (int i = 24; i >= 0; i--) {
            idle -= min(maxf - 1, freq[i]);
        }
        
        return max(0, idle) + tasks.size();
        // we return size() + num of idle cycles we need
        // this is garunteed to give us true minimum
    }
};
