/*
We can ignore any triplet with a value greater then the corresponding target value

From the remaining triplets, we only need to check that all three target values exist

If they do then we can return true

First I'll do it with O(n) space as I already know how, then i can try reduce this
*/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> hset;

        for (const auto& trip : triplets) {
            if (trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[2]) {
                continue;
            }

            for (int i = 0; i < trip.size(); i++) {
                if (trip[i] == target[i]) {
                    hset.insert(i);
                }
            }
        }
        return hset.size() == 3;
    }
};
