/*
We are concerned with the frequency of letters
so we should make a hashmap of frequencies or a vector thats size 26?? Dont think it matters

this can acc be improved on i think
we can keep a hashmap that stores the last index of every char used,


Only thing to consider now is tech

We should probs use two pointer algo, then size of cur substring is just r - l + 1
when we need to move on we just set l = r + 1
otherwise we just r++
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }
        vector<int> res;
        int size = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, lastIndex[s[i]]);

            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};
