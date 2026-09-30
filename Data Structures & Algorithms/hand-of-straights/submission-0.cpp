class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // sort hand
        // then create hash map to store frequencies of elems
        // we iterate through 

        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> fs;
        for (int card : hand) fs[card]++;

        sort(hand.begin(), hand.end());

        for (int card : hand) {
            if (fs[card] > 0) {
                for (int i = card; i < card + groupSize; i++) {
                    if (fs[i] == 0) return false;
                    fs[i]--;
                }
            }
        }
        return true;
    }
};
